#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
// #define MOD 1000000007
const unsigned int MOD = 1e9+7;


typedef long long ll;
typedef pair<int, int> p;

ll dp[200][4][4][4];

void init(){
  dp[0][3][3][3] = 1;
}

ll n;

void solve(){
  for (int len = 0; len < n; len++) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          if(dp[len][i][j][k] == 0) continue;
          for (int a = 0; a < 4; a++) {
            if(a == 2 && i == 1 && j == 0) continue;
            if(a == 1 && i == 2 && j == 0) continue;
            if(a == 2 && i == 0 && j == 1) continue;
            if(a == 2 && i == 1 && k == 0) continue;
            if(a == 2 && j == 1 && k == 0) continue;

            dp[len+1][a][i][j] += dp[len][i][j][k];
            dp[len+1][a][i][j] %= MOD;
          }
        }
      }
    }
  }
  ll res = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        res += dp[n][i][j][k];
        res %= MOD;
      }
    }
  }

  cout << res << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  init();
  solve();
}
