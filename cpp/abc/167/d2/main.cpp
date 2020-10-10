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
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  rep(i, n){
    cin >> v[i];
    v[i]--;
  }
  int logK = 1;
  while((1ll << logK) < k) logK++;


  // iから2^k進んだ町
  vector<vector<ll>> doubling(logK, vector<ll>(n));

  rep(i, n) doubling[0][i] = v[i];

  for (int i = 1; i < logK; ++i) {
    for (int j = 0; j < n; ++j) {
      doubling[i][j] = doubling[i-1][doubling[i-1][j]];
    }
  }

  int node = 0;
  rep(d, 60){
    if(k & (1ll << d)) node= doubling[d][node];
  }

  cout << node+1 << endl;

}
