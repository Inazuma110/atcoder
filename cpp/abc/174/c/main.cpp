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

ll k;

ll f(ll x){
  return ((10 * x) % k + 7) % k;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k;
  for (int i = 0; i < 50000000; ++i) {
    ll tmp  = 7 * ;
    if(tmp % k == 0){
      cout << i+1 << endl;
      exit(0);
    }
    tmp = f(tmp);
  }

  cout << -1 << endl;


}
