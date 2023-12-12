#include <bits/stdc++.h>
using namespace std;
int main(){
    // ac code
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int> pq2;
    int n; cin >> n;
    while(n--){
        int op, mode; cin >> op >> mode;
        if(op == 1){
            int val; cin >> val;
            if(mode == 1) pq1.push(val);
            else pq2.push(val);
        }
        else if(op == 2){
            if(mode == 1){
                if(!pq1.empty()){
                    cout << pq1.top() << "\n";
                    pq1.pop();
                }
                else cout << -1 << "\n";
            }
            else {
                if(!pq2.empty()){
                    cout << pq2.top() << "\n";
                    pq2.pop();
                }
                else cout << -1 << "\n";
            }
        }
        else if(op == 3){
            if(mode == 1){
                if(!pq1.empty()){
                    cout << pq1.top() << "\n";
                }
                else cout << -1 << "\n";
            }
            else {
                if(!pq2.empty()){
                    cout << pq2.top() << "\n";
                }
                else cout << -1 << "\n";
            }
        }
        else {
            cout << (mode == 1 ? pq1.size() : pq2.size()) << "\n";
        }
    }
}