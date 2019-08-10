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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long double> t(n+1, 1), a(n+1, 1);
  rep(i, n) cin >> t[i+1] >> a[i+1];

  vector<ll> dpt(n + 1000, 1);
  vector<ll> dpa(n + 1000, 1);
  for (int i = 1; i <= n; i++) {
    ll now = max(ceil(dpt[i-1]/t[i]), ceil(dpa[i-1] / a[i]));
    dpt[i] = now * t[i];
    dpa[i] = now * a[i];
  }
  // cout << t[n] << endl;
  // cout << a[n] << endl;
  cout << dpt[n] + dpa[n] << endl;

}
