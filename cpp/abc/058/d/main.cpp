#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;

long long comb(int n, int r) {
  if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
  long long ans = 1;

  for(int i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
    // ans %= MOD;
  }

  return ans;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll h, w, a, b;
  cin >> h >> w >> a >> b;
  a = h - a+1;
  h--;w--;
  a--;b--;
  ll res = comb(h + w, h);
  cout <<res << endl;
  ll tmp = comb(a+b, a) * comb(h+w-a-b, h-a);
  // tmp %= MOD;
  cout <<tmp << endl;
  cout << res - tmp << endl;

}
