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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;

  for (ll i = 1; i <= n; ++i) {
    ll count = 0;

    for (ll x = 1; x*x <= i; ++x) {
      ll val = x*x;
      for (ll y = 1; y*y <= i-val; ++y) {
        ll val2 = val + y*y+x*y;
        if(val2 > i) break;
        for (int z = 1; z*z <= i-val2; ++z) {
          ll val3 = val2 + z*z + z*x + z*y;
          if(val3 == i) count++;
          if(val3 >= i) break;
        }
      }
    }
    cout << count << endl;
  }
}
