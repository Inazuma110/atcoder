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
  vector<ll> bits(45);
  rep(i, n){
    cin >> v[i];
    rep(j, 45) if((1ll << j) & v[i]) bits[j]++;
    // print(bits);
  }

  ll res = 0;

  for (int i = 44; i >= 0; i--) {
    if(bits[i] * 2ll < n && k >= (1ll << i)){
      res += (n-bits[i]) * (1ll << i);
      k -= (1ll << i);
    }else{
      res += bits[i] * (1ll << i);
    }
  }
  cout << res << endl;

}
