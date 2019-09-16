#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  int n;
  cin >> n;
  // vector<vector<int>> v(n, vector<int> (n-1));
  int v[1010][1010];
  rep(i, n) rep(j, n-1){
    cin >> v[i][j];
    v[i][j]--;
  }
  vector<int> index(n, 0);
  // int index[1010];

  for (int i = 1; i <= ((n-1) * n) / 2; i++) {
    vector<bool> battled(n, false);
    // bool battled[1010];
    // rep(j, 1010) battled[j] = false;
    // cout << "===" << endl;
    // cout << i << endl;
    bool flag = true;
    for (int j = 0; j < n; j++) {
      if(index[j] >= n-1) continue;
      int enemy = v[j][index[j]];
      if(index[j] >= n-1 || index[enemy] >= n-1) continue;
      if(v[enemy][index[enemy]] == j && !battled[j] && !battled[enemy]){
        flag = false;
        battled[j] = true;
        battled[enemy] = true;
        index[enemy]++;
        index[j]++;
      }
    }
    if(flag) break;

    flag = true;
    rep(j, n){
      if(index[j] < n-1) {
        flag = false;
        break;
      }
    }
    if(flag){
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;

}
