#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;

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

set<int> yakusu(ll x){
  set<int> yakusu;
  for (int i = 1; i*i <= x; i++) {
    if(x % i == 0){
      yakusu.insert(i);
      yakusu.insert(x / i);
    }
  }
  return yakusu;

}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  sort(ALL(v));
  ll sum = 0;
  rep(i, n) sum += v[i];
  set<int> s = yakusu(sum);
  ll ans = 1;

  for(ll a : s){
    ll need = LLONG_MAX;
    vector<ll> r(n);
    rep(i, n) r[i] = v[i] % a;
    sort(ALL(r));
    ll A = 0, B = 0;
    rep(i,n) B += a-r[i];
    rep(i, n){
     A += r[i];
     B -= a - r[i];
     need = min(need, max(A, B));
    }
    if(need <= k) ans = max(ans, a);
  }
  cout << ans << endl;

}
