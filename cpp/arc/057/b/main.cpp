#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  // i日目にj日機嫌が良い時の最小勝利数
  vector<vector<int>> dp(n+3, vector<int>(n+3, INT_MAX/2));
  rep(i, n+3) dp[i][0] = 0;
  rep(i, n+3) dp[i][1] = 1;
  rep(i, n+3) dp[1][1] = 1;

  for (int i = 2; i <= n; ++i) {
    ll battle = v[0];
    for (int j = 2; j <= i; ++j) {
      long double rate1 = double(dp[i-1][j-1]) / double(battle);
      battle += v[i-1];
      long double rate2 = double(dp[i-1][j-1]) / double(battle);
      int win = 0;
      while(rate2 <= rate1 && rate2 <= 1 && rate1 <= 1){
        win++;
        rate2 = double(dp[i-1][j-1] + win) / double(battle);
      }
      if(rate2 <= rate1 || rate2 > 1) win = INT_MAX / 2;
      // cout << rate1 << endl;
      // cout << rate2 << endl;
      // cout << win << endl;
      dp[i][j] = min(dp[i-1][j-1] + win, dp[i-1][j]);
      // dp[i][j] = dp[i-1][j];
    }
  }

  // print(dp);
  int maxv = -1;
  rep(i, n+3) rep(j, n+3){
    if(dp[i][j] <= k && j > maxv) maxv = j;
  }

  cout << maxv << endl;
}
