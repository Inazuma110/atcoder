#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;

long long comb(int n, int r) {
  if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
  long long ans = 1;

  for(int i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans %= MOD;
    ans /= i;
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  cout << comb(1997, 2) << endl;

  int blue = k;
  int red = n-k;
  for (int i = 0; i < k; i++) {
    ll res = 0;
    ll shikiri_pattern = comb(blue-1, i) % MOD;
    ll can_input = i + 2;
    ll nokori = red - i;
    if(nokori == 0){
      cout << 1 << endl;
      continue;
    }
    // if(nokori + 1 < can_input){
    //   int tmp = nokori+1;
    //   nokori = can_input-1;
    //   can_input = tmp;
    // }
    res += shikiri_pattern * comb(can_input+nokori+1, can_input);
    res %= MOD;
    cout << res << endl;
    // cout << "==========" << endl;
  }
}
