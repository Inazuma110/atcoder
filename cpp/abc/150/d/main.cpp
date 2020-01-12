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

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  else return gcd(b, a % b);
  // return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  ll g = gcd(a, b);
  return a / g * b;
}

int f(int x){
  int res = 0;
  while(x > 0 && x % 2 == 0){
    x /= 2;
    res++;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  vector<ll> v(n);
  rep(i, n){
    cin >> v[i];
    if(v[i] % 2 == 0) v[i] /= 2;
    else{
      cout << 0 << endl;
      return 0;
    }
  }
  ll l = 1;
  int t = f(v[0]);
  rep(i, n){
    if(f(v[i]) != t){
      cout << 0 << endl;
      return 0;
    }
    v[i] >>= t;
  }
  m >>= t;

  rep(i, n){
    l = lcm(l, v[i]);
    if(l > m) {
      cout << 0 << endl;
      return 0;
    }
  }
  m /= l;
  int res = (m+1) / 2;
  cout << res << endl;
}
