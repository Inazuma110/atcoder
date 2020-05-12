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

typedef long long ll;
typedef pair<ll, ll> p;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];

  vector<ll> dp(n, 1);
  vector<ll> s(n);
  vector<ll> mul(n);
  for (int i = 1; i < n; i++) {
    dp[i] = dp[i-1] * i;
    dp[i] %= MOD;
  }

  for (int i = 1; i < n; i++) {
    s[i] = dp[n-1] / i;
  }

  ll res = 0;
  for (int i = 1; i < n; i++) {
    mul[i] = s[i] + mul[i-1];
    mul[i] %= MOD;
    res += mul[i];
  }

  cout << res << endl;

}
