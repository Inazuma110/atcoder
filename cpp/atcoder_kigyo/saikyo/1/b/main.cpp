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

struct mint {
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};


typedef pair<mint, mint> p;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  mint res = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  map<ll, p> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if(v[i] > v[j]) mp[i].first.x++;
    }
    for (int j = i + 1; j < n; j++) {
      if(v[i] > v[j]) mp[i].second.x++;
    }
  }
  // ll a = 1000000001ll * 1000000000ll;
  // cout << a << endl;

  for(auto a : mp){
    mint tmp = (a.second.second) * (((1ll + k) * k) / 2ll);
    res += tmp;
    tmp = (a.second.first) * (((-1ll + k) * k) / 2ll);
    res += tmp;
  }


  cout << res.x << endl;
}
