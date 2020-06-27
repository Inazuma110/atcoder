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

  ll res = 0;
  for (ll i = 2; i*i <= n; ++i) {
    ll tmp = n;
    while(tmp % i == 0){
      tmp /= i;
    }
    if(tmp % i == 1) res++;

    if(i * i != n && n / i != i){
      tmp = n;
      ll x = tmp / i;
      while(tmp % x == 0){
        tmp /= x;
      }
      if(tmp % x == 1) res++;
    }
  }
  res++;
  if(n > 2) res++;
  cout << res << endl;
}
