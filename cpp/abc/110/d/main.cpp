#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn int

#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> p;


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

vector<pair<ll, int>> factoring(ll a){
  vector<pair<ll, int>> v;
  for (int i = 2; i <= a; i++) {
    if(a % i == 0){
      int count = 0;
      while(a % i == 0){
        count++;
        a /= i;
      }
      v.push_back({i, count});
    }
  }
  return v;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<ll, int>> v = factoring(m);
  ll res = 1;
  for (pair<ll, int> a : v) {
    res *= comb(a.second + n - 1, n - 1);
    res %= MOD;
  }
  cout << res << endl;
}
