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
typedef pair<ll, ll> p;

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

map<ll, p> mp;
void init(){
  for (int i = 0; i < 3 * 100000; i++) {
    mp[i].first = -1;
    mp[i].second = 0;
  }
}

int main(){
  ll n;
  cin >> n;
  vector<ll> v(n);
  cin >> v[0];
  int index = 1;
  for (int i = 1; i < n; i++) {
    cin >> v[index];
    if(v[index] != v[index-1]) index++;
  }
  n = index;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  init();

  ll store = 0;
  ll res = 1;
  vector<ll> num(300000, 0);
  for (int i = 0; i < n; i++) {
    if(mp[v[i]].first != -1){
      // cout << 111 << endl;
      // res += mp[v[i]].second + num[v[i]];
      res += pow(2, mp[v[i]].second) + num[v[i]];
      res %= MOD;
      store++;
    }else{
      mp[v[i]].second = store;
    }
    mp[v[i]].first = i;
    num[v[i]]++;
  }

  cout << res << endl;

  // for (int i = 1; i <= 5; i++) {
  //   cout << i << endl;
  //   cout << mp[i].first << " : " << mp[i].second << endl;
  //   cout << "====" << endl;
  // }


  // if(v[0] != v[1]) mp[v[0]]++;
  // for (int i = 1; i < n; i++) {
  //   if(v[i-1] != v[i]) mp[v[i]]++;
  // }
  //
  // ll res = 1;
  // for(auto a : mp){
  //   if(a.second >= 2){
  //     res += comb(a.second, 2);
  //     res %= MOD;
  //   }
  // }
  // cout << res << endl;
}
