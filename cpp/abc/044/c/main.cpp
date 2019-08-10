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

// dp[i][j][k] = x0~xi からj選んで和がkな数
ll dp[60][60][10100];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a;
  cin >> n >> a;
  vector<ll> v(n);
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 2500; k++) {
        if(dp[i][j][k]){
          dp[i+1][j][k] += dp[i][j][k];
          dp[i+1][j+1][k + v[i]] += dp[i][j][k];
        }
      }
    }
  }

  ll res = 0;
  for (int i = 1; i <= n; i++) {
    res += dp[n][i][i * a];
  }
  cout << res << endl;
}
