#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
// using namespace atcoder;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;

ll dp[4][3005][3005];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll r, c, k;
  cin >> r >> c >> k;
  vector<vector<ll>> g(r, vector<ll>(c));
  rep(i, k){
    ll y, x, val;
    cin >> y >> x >> val;
    y--;x--;
    g[y][x] = val;
  }
  rep(i, 3005) rep(j, 3005) rep(k, 4) dp[k][i][j] = 0;

  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      dp[0][i][j] = dp[0][i][j-1];
      rep(K, 4) chmax(dp[0][i][j], dp[K][i-1][j]);

      if(g[i-1][j-1] != 0){
        dp[1][i][j] = max({dp[1][i][j-1], dp[0][i][j-1]+g[i-1][j-1], dp[0][i][j]+g[i-1][j-1]});
        dp[2][i][j] = max(dp[2][i][j-1], dp[1][i][j-1]+g[i-1][j-1]);
        dp[3][i][j] = max(dp[3][i][j-1], dp[2][i][j-1]+g[i-1][j-1]);
      }else{
        dp[1][i][j] = dp[1][i][j-1];
        dp[2][i][j] = dp[2][i][j-1];
        dp[3][i][j] = dp[3][i][j-1];
      }
    }
  }

  ll res = max({dp[0][r][c], dp[1][r][c], dp[2][r][c], dp[3][r][c]});
  cout << res << endl;
}
