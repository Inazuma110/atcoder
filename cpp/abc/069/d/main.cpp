#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

int main(){
  int h, w;
  cin >> h >> w;
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int use = 1;
  int count = 0;
  int index = 0;
  vector<vector<int>> vv(h,vector<int>(w, 0));
  for (int i = 0; i < h; i++) {
    if(i % 2 == 0){
      for (int j = 0; j < w; j++) {
        if(count >= v[index]){
          index++;
          count = 0;
          use++;
        }
        vv[i][j] = use;
        count++;
      }
    }else{
      for (int j = w-1; j >= 0; j--) {
        if(count >= v[index]){
          index++;
          count = 0;
          use++;
        }
        vv[i][j] = use;
        count++;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if(j != w-1) cout << vv[i][j] << " ";
      else cout << vv[i][j];
    }
    cout << endl;
  }


}
