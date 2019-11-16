#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
typedef cpp_int ll;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 998244353

// typedef long long ll;
typedef pair<ll, ll> p;

ll mod_pow(ll a, int p){
  if(p == 0) return 1;
  if(p % 2 == 0){
    int half_p = p / 2;
    ll half = mod_pow(a, half_p);
    return half * half % MOD;
  }else{
    return a * mod_pow(a, p-1) % MOD;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v(n);
  map<ll, int> mp;
  rep(i, n){
    cin >> v[i];
    mp[v[i]]++;
  }
  ll res = 1;
  if(v[0] != 0 || mp[0] != 1) res = 0;


  for (int i = 1; i < n; i++) {
    res *= mod_pow(mp[i-1], mp[i]);
    res %= MOD;
  }
  cout << res << endl;

}
