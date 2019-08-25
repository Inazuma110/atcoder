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
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<int> v(n);
  ll res = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  map<ll, p> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if(v[i] > v[j]) mp[i].first++;
    }
    for (int j = i + 1; j < n; j++) {
      if(v[i] > v[j]) mp[i].second++;
    }
  }
  // ll a = 1000000001ll * 1000000000ll;
  // cout << a << endl;

  for(auto a : mp){
    ll tmp = (a.second.second % MOD) * ((((1ll + k) * k) / 2ll) % MOD);
    tmp %= MOD;
    res += tmp;
    res %= MOD;
    tmp = (a.second.first % MOD) * ((((-1ll + k) * k) / 2ll) % MOD);
    tmp %= MOD;
    res += tmp;
    res %= MOD;
  }


  cout << res << endl;
}
