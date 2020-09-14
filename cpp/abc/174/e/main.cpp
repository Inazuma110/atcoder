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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll maxv = -1;
  rep(i, n){
    cin >> a[i];
    chmax(maxv, a[i]);
  }
  auto f = [&](ll v){
    ll count = 0;
    for (ll i = 0; i < n; i++) {
      count += (a[i]-1)/v;
      // count += a[i]/v;
      // count += a[i] % v != 0;
    }
    // if(count <= k) chmin(maxv, v);
    return count <= k;
  };

  ll ng = 0;
  ll ok = LLONG_MAX / 2;
  // if(k == 0) {
  //   return 0;
  // }
  while (ok - ng > 1) {
    ll mid = (ng + ok) / 2;
    if(f(mid))
      ok = mid;
    else
      ng = mid;
  }

  cout << ok << endl;
}
