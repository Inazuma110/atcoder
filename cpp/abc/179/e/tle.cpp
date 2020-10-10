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
ll n, x, m;

vector<ll> dp;
void f(int a, ll m){
  for (int i = 1; i < n; ++i) {
    dp[i] = (dp[i-1] * dp[i-1]) % m;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x >> m;

  dp = vector<ll> (1000000, -1);
  dp[0] = x;

  ll res = 0;
  f(n+1, m);

  rep(i, n) res += dp[i];

  cout << res << endl;
}
