#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;

// DPテーブル
const int MAX_N = 10100;
const int MAX_W = 10100;
int dp[MAX_N][MAX_W]; // 12 種類だが余裕をもつ

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, n;
  cin >> h >> n;
  vector<int> a(n), b(n);
  rep(i, n){
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i < MAX_N; ++i) for (int w = 0; w < MAX_W; ++w) dp[i][w] = INT_MAX / 2;
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= h; j++) {
      dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
      dp[i+1][min(j+a[i], h)] = min(dp[i+1][j]+b[i], dp[i+1][min(j+a[i], h)]);
    }
  }

  cout << dp[n][h] << endl;
}
