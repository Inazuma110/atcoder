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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x, k, d;
  cin >> x >> k >> d;
  if(x < 0) {
    ll tmp = x;
    x += min(k, (abs(x) + d - 1) / d) * d;
    k -= min(k, (abs(tmp) + d - 1) / d);
  }
  else {
    ll tmp = x;
    x -= min(k, abs(x) / d) * d;
    k -= min(k, abs(tmp) / d);
  }
  k %= 2;
  x -= k * d;
  cout << abs(x) << endl;
    // cout << x << ' ' << k << ' ' << d << endl;

}
