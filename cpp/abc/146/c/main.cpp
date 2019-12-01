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

typedef long long ll;
// typedef cpp_int ll;
typedef pair<ll, ll> p;

ll a, b, x;

// f(x) がtrueな最小のx
ll f(ll tmp){
  if(a > x) return false;
  if(b > x) return false;
  if(tmp > x) return false;
  if(a * tmp > x) return false;
  if(b * ll(to_string(tmp).size()) > x) return false;

  if(a * tmp + b * ll(to_string(tmp).size()) <= x) return true;
  else return false;

}


ll bs(ll s, ll t){
  ll ng = s - 1, ok = t;
  while (abs(ng - ok) > 1) {
    ll mid = (ng + ok) / 2;
    // cout << mid << endl;
    (f(mid) ? ok : ng) = mid;
  }

  if(ok >= 1000000000) return 1000000000;
  return ok;
}

int main(){
ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> x;
  ll l = 0, r = 1000000001;

  auto keta = [&](ll c){
    int res = 0;
    while(c){
      c /= 10;
      res++;
    }
    return res;
  };

  auto f = [&](ll c){
    return a*c + b*keta(c);
  };

  while(r - l > 1){
    ll c = (l+r) / 2;
    if(f(c) <= x) l = c;
    else r = c;
  }
  cout << l << endl;


}
