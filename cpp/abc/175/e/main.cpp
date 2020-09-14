#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

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

int dp[3100][3100][3];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c, K;

  cin >> r >> c >> K;
  vector<vector<int>> v(r, vector<int>(c, 0));
  rep(i, K){
    int R, C, V;
    cin >> R >> C >> V;
    R--; C--;
    v[R][C] = V;
  }

  rep(i, 3100) rep(j, 3100) rep(k, 3) dp[i][j][k] = 0;
  dp[0][0][0] = v[0][0];
  dp[0][0][1] = v[0][0];
  dp[0][0][2] = v[0][0];

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if(i == 0 && j == 0) continue;
      if(j == 0){
        dp[i][j][0] = v[i][j];
        if(i != 0) dp[i][j][0] += dp[i-1][j][0];
      } else {
        if(i != 0) dp[i][j][0] = max(dp[i][j-1][0], dp[i-1][j][0]);
        else dp[i][j][0] = max(dp[i][j-1][0], v[i][j]);
      }
    }
  }


  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if(i == 0 && j == 0) continue;
      if(j == 0){
        dp[i][j][1] = dp[i][j][0];
        // if(i != 0) dp[i][j][1] += dp[i-1][j][1];
      } else {
        if(i != 0) dp[i][j][1] = max(dp[i][j-1][1], dp[i-1][j][1]+v[i][j]);
        else dp[i][j][1] = max(dp[i][j-1][0] + v[i][j], dp[i][j-1][1]);
      }
      // dp[i][j][1] = max(dp[i][j-1][0] + v[i][j], dp[i][j-1][1]);
      // if(i != 0) dp[i][j][1] = max({dp[i][j][1], dp[i-1][j][1]+v[i][j]});
    }
  }

  // print(v);
  // rep(i, 30){
  //   rep(j, 30) cout << dp[i][j][1] << ' ';
  //   cout << endl;
  // }

  for (int i = 0; i < r; i++) {
    for (int j = 1; j < c; j++) {
      if(i == 0 && j == 0) continue;
      if(j == 0){
        dp[i][j][2] = dp[i][j][1];
        // if(i != 0) dp[i][j][1] += dp[i-1][j][1];
      } else {
        if(i != 0) dp[i][j][2] = max(dp[i][j-1][2], dp[i-1][j][2]+v[i][j]);
        else dp[i][j][2] = max(dp[i][j-1][1] + v[i][j], dp[i][j-1][2]);
      }
    }
  }

  cout << dp[r-1][c-1][2] << endl;
}
