#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/operators.hpp>

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
  int n;
  cin >> n;
  vector<ll> v(n+1);
  rep(i, n+1) cin >> v[i];
  // dp[i] = 上から見た時のi番目の最大頂点数
  vector<ll> dp(n+10, -1);
  dp[0] = 1;

  // n == 0の時の処理
  if(n == 0 && v[0] > 1){
    cout << -1 << endl;
    return 0;
  }else if(n == 0 && v[0] == 1){
    cout << 1 << endl;
    return 0;
  }else if(n == 0){
    cout << -1 << endl;
    return 0;
  }

  ll res = 0;
  // 上から見るか
  for (int i = 0; i < n; ++i) {
    if(dp[i] - v[i] > LLONG_MAX / 2) dp[i+1] = LLONG_MAX;
    else dp[i+1] = (dp[i] - v[i]) * 2;
  }

  // ans[i] = 深さiの最大頂点数
  vector<ll> ans(n+1);
  // 下から見るか
  ans[n] = v[n];
  for (int i = n; i >= 1 ; --i) {
    // cout << dp[i-1] << ' ' << ans[i]+v[i-1] << endl;
    ans[i-1] = ans[i] + v[i-1];
  }
  rep(i, n+1) chmin(ans[i], dp[i]);
  // print(dp);
  // print(ans);

  // 構築できるかチェック
  bool flag = false;
  for(int i = 0; i < n; i++){
    res += ans[i];
    if(ans[i] <= v[i]) flag = true;
  }
  if(ans[n] != v[n]) flag = true;
  res += ans[n];
  // res += ans[n];
  // print(ans);

  if(flag) cout << -1 << endl;
  else cout << res << endl;
}
