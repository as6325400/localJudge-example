#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int maxn = 1e6 + 5;
struct priority_queue {
    int size;
    int mode;
    int *heap;
} typedef priority_queue;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
bool cmp(int par, int child, int mode){
    // mode == 1, min_heap
    if(mode == 1) return par <= child;
    else return par >= child;
}
void child_to_par_heapify(priority_queue *pq, int child){
    int par = (child - 1) / 2;
    if(child > 0){
        if(!cmp(pq->heap[par], pq->heap[child], pq->mode)){
            swap(pq->heap + par, pq->heap + child);
            child_to_par_heapify(pq, par);
        }
    }
}
void par_to_child_heapify(priority_queue *pq, int par){
    int tar = par, lc = 2 * par + 1, rc = 2 * par + 2;
    if(lc < pq->size) tar = cmp(pq->heap[tar], pq->heap[lc], pq->mode) ? tar : lc;
    if(rc < pq->size) tar = cmp(pq->heap[tar], pq->heap[rc], pq->mode) ? tar : rc;
    if(par == tar) return;
    swap(pq->heap + par, pq->heap + tar);
    par_to_child_heapify(pq, tar);
}
void push(priority_queue *pq, int val){
    pq->heap[pq->size] = val;
    child_to_par_heapify(pq, pq->size++);
}
int pop(priority_queue *pq){
    if(pq->size == 0) return -1;
    pq->size--;
    swap(pq->heap + 0, pq->heap + pq->size);
    par_to_child_heapify(pq, 0);
    return pq->heap[pq->size];
}
int size(priority_queue *pq){
    return pq->size;
}
int top(priority_queue *pq){
    if(pq->size == 0) return -1;
    return pq->heap[0];
}
int main(){
    priority_queue min_heap = {0, 1, NULL}, max_heap = {0, 2, NULL};
    min_heap.heap = (int*)malloc(sizeof(int) * maxn);
    max_heap.heap = (int*)malloc(sizeof(int) * maxn);
    int n; scanf("%d", &n);
    while(n--){
        int op, mode; scanf("%d%d", &op, &mode);
        if(op == 1){
            int val; scanf("%d", &val);
            if(mode == 1) push(&min_heap, val);
            else push(&max_heap, val);
        }
        else if(op == 2){
            if(mode == 1) printf("%d\n", pop(&min_heap));
            else printf("%d\n", pop(&max_heap));
        }
        else if(op == 3){
            if(mode == 1) printf("%d\n", top(&min_heap));
            else printf("%d\n", top(&max_heap));
        }
        else {
            if(mode == 1) printf("%d\n", size(&min_heap));
            else printf("%d\n", size(&max_heap));
        }
    }
    return 0;
}