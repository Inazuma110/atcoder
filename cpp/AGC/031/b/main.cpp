#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

typedef long long ll;
typedef pair<int, int> p;

long mod_pow(ll a, int p){
  if(p == 0) return 1;
  if(p % 2 == 0){
    int half_p = p / 2;
    long half = mod_pow(a, half_p);
    return half * half % MOD;
  }else{
    return a * mod_pow(a, p-1) % MOD;
  }
}

long long comb(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)

    ll mul = 1;
    ll div = 1;
    for(int i = 0; i < r; i++) {
      mul *= (n-i);
      div *= (i+1);
      mul %= MOD;
      div %= MOD;
    }
    ll ans = mul * mod_pow(div, MOD-2) % MOD;
    return ans;
}

int main(){
  ll n;
  cin >> n;
  vector<ll> v(n);
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }

  if(v[0] != v[1]) mp[v[0]]++;
  for (int i = 1; i < n; i++) {
    if(v[i-1] != v[i]) mp[v[i]]++;
  }

  ll res = 1;
  for(auto a : mp){
    if(a.second >= 2){
      res += comb(a.second, 2);
      res %= MOD;
    }
  }
  cout << res << endl;

}
