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
  int n;
  cin >> n;
  vector<ll> y(n), x(n);
  rep(i, n) cin >> x[i] >> y[i];
  vector<ll> v1(n), v2(n);
  rep(i, n){
    v1[i] = x[i]+y[i];
    v2[i] = x[i]-y[i];
  }
  sort(ALL(v1));
  ll res = v1[n-1] - v1[0];
  sort(ALL(v2));
  chmax(res, v2[n-1]-v2[0]);

  cout << res << endl;



}

