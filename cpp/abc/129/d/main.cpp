#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  vector<vector<int>> vv(h, vector<int> (w));
  vector<vector<int>> vv2(h, vector<int> (w));
  for (int i = 0; i < h; i++) {
    cin >> v[i];
    for (int j = 0; j < w; j++) {
      if(v[i][j] == '#') {
        vv[i][j] = -1;
        vv2[i][j] = -1;
      }
      else{
        vv[i][j] = 1;
        vv2[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 1; j < w; j++) {
      if(vv[i][j-1] != -1 && vv[i][j] != -1) vv[i][j] += vv[i][j-1];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = w-2; j >= 0; j--) {
      if(vv[i][j+1] != -1 && vv[i][j] != -1){
        vv[i][j] = vv[i][j+1];
      }
    }
  }

  for (int i = 0; i < w; i++) {
    for (int j = 1; j < h; j++) {
      if(vv2[j-1][i] != -1 && vv2[j][i] != -1) vv2[j][i] += vv2[j-1][i];
    }
  }
  for (int i = 0; i < w; i++) {
    for (int j = h-2; j >= 0; j--) {
      if(vv2[j+1][i] != -1 && vv2[j][i] != -1){
        vv2[j][i] = vv2[j+1][i];
      }
    }
  }

  int res = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      res = max(res, vv[i][j] + vv2[i][j] - 1);
    }
  }
  cout << res << endl;

}
