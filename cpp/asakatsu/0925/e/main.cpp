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

int dp[105][4][2];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = int(s.size());
  int K;
  cin >> K;
  dp[0][0][0] = 1;
  rep(i, n) rep(j, 4) rep(k, 2){
    int d = s[i] - '0';
    rep(nd, 10){
      int ni = i+1, nj = j, nk = k;
      if(nd != 0) nj++;
      if(nj > K) continue;
      if(k == 0){
        if(nd > d) continue;
        if(nd < d) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  cout << dp[n][K][0] << endl;
  ll res = dp[n][K][0] + dp[n][K][1];
  cout << res << endl;

}
