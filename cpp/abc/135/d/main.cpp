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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  const int n = 13;
  vector<ll> dp(n);
  dp[0] = 1;

  ll mul = 1;
  for (int i = int(s.size()) - 1; i >= 0; i--) {
    vector<ll> next_dp(n);
    auto c = s[i];
    if(c == '?'){
      for (int k = 0; k < 10; k++) {
        for (int j = 0; j < n; j++) {
          next_dp[(k * mul + j) % n] += dp[j];
          next_dp[(k * mul + j) % n] %= MOD;
        }
      }
    }else{
      int k = int(s[i] - '0');
      for (int j = 0; j < n; j++) {
        next_dp[(k * mul + j) % n] += dp[j];
        next_dp[(k * mul + j) % n] %= MOD;
      }
    }
    mul *= 10;
    mul %= n;
    dp = next_dp;
  }
  cout << dp[5] << endl;

}
