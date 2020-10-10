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
  ll n;
  cin >> n;
  vector<p> v(n);
  ll num = 0;
  rep(i, n) cin >> v[i].first;
  rep(i, n) cin >> v[i].second, num += v[i].second;
  sort(ALL(v));
  long double c = 0;
  ll now = num;
  for (int i = 0; i < n; ++i) {
    now -= v[i].second;
    if(num % 2 == 1){
      if(now <= num/2+1){
        c = v[i].first;
        break;
      }
    }else{
      if(now == num/2){
        c = (double)(v[i].first+v[i+1].first) / 2.0;
        break;
      } else if(now < num/2){
        c = v[i].first;
        break;
      }
    }
  }

  auto f = [&](long double x){
    ll val = 0;
    bool next = 0;
    rep(i, n){
      val += v[i].second*abs(x-v[i].first);
      if(x-(ll)x == 0.5 && v[i].second % 2 == 1){
        if(next) next=0, val++;
        else next = 1;
      }
    }
    return (ll)val;
  };

  cout << c << ' ' << f(c) << endl;
}
