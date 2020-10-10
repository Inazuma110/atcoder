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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n){
    cin >> v[i];
    v[i] %= 10;
  }
  vector<vector<int>> dp(n+10, vector<int>(10, -1));
  // dp[i][j] = iまでのカードでjにする最大枚数
  // rep(i, 10) dp[0][i] = 0;
  dp[0][v[0]] = 1;

  for (int i = 1; i <= n; ++i) {
    rep(j, 10) dp[i][j] = dp[i-1][j];
    rep(j, 10){
      int tmp = j - v[i];
      if(tmp < 0) tmp += 10;
      if(dp[i-1][tmp] == -1) continue;
      dp[i][j] = max(dp[i-1][j], dp[i-1][tmp] + 1);
    }
  }


  if(dp[n-1][0] == -1) cout << 0 << endl;
  else cout << dp[n-1][0] << endl;


}
