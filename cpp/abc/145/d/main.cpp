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
typedef pair<ll, ll> p;

const int MAX = 5100000;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll com(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x, y;
comb_init();
  cin >> x >> y;
  ll cnt = 0;
  ll res = 0;
  while(true){
    ll x1 = 0;
    ll x2 = 0;
    ll y1 = 0, y2 = 0;
    // if(x % 2 == 0){
      x2 = cnt;
      x1 = x - (x2 * 2);
      y2 = x1;
      y1 = x2;
    // }

    if(x1 + x2*2 == x && y1 + y2*2 == y) {
      res += com(x1+x2, x1);
      res %= MOD;
    }else if(cnt > x && cnt > y) break;
    cnt++;
  }
  cout << res << endl;
}
