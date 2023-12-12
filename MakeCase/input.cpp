#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 11;
  srand(time(nullptr));

  vector<int> save = {0, 0, 0, 10, 10, 10, 10, 15, 20, 25, 1000, 1000000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
      cerr << "Cants open file " << i << endl;
    }

    int num = save[i];
    inputFile << num << '\n';

    for(int j = 0; j < num; j++){
      int mode = rand() % 6, q = rand() % 2 + 1;
      if(mode <= 2) inputFile << 1 << ' ' << q << ' ' <<rand() % (int)(1e9) + 1 << '\n';
      else if(mode == 3) inputFile << 2 << ' ' << q << '\n';
      else if(mode == 4) inputFile << 3 << ' ' << q << '\n';
      else inputFile << 4 << ' ' << q << '\n';
    }
    inputFile.close();
  }
  return 0;
}
