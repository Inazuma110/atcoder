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
typedef pair<ll, ll> p;

int dp[10000][10000];




int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for (int i = n-1; i >= 0; i--) {
    if(s[n-1] == s[i]) dp[n-1][i] = 1;
  }
  for (int i = n-2; i >= 0; i--) {
    for (int j = n-1; j >= 0; j--) {
      dp[i][j] = (s[i] == s[j]) ? dp[i+1][j+1] + 1 : 0;
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int now = min(dp[i][j], j-i);
      res = max(res, now);
    }
  }
  cout << res << endl;
}
