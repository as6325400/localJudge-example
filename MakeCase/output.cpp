#include<bits/stdc++.h>
#define int long long

using namespace std;


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  priority_queue<int, vector<int>, greater<int>> a;
  priority_queue<int, vector<int>> b;
  int n;
  input >> n;
  for(int i = 0; i < n; i++){
    int mode, q;
    input >> mode >> q;
    if(mode == 1){
      int num;
      input >> num;
      if(q == 1) a.push(num);
      else b.push(num);
    }
    else if(mode == 2){
      if(q == 1){
        if(a.empty()) output << -1 << '\n';
        else{
          output << a.top() << '\n';
          a.pop();
        }
      }
      else{
        if(b.empty()) output << -1 << '\n';
        else{
          output << b.top() << '\n';
          b.pop();
        }
      }
    }
    else if(mode == 3){
      if(q == 1){
        if(a.empty()) output << -1 << '\n';
        else{
          output << a.top() << '\n';
        }
      }
      else{
        if(b.empty()) output << -1 << '\n';
        else{
          output << b.top() << '\n';
        }
      }
    }
    else{
      if(q == 1){
        output << a.size() << '\n';
      }
      else{
        output << b.size() << '\n';
      }
    }
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  // secret testcase
  int testCaseName = 11;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 