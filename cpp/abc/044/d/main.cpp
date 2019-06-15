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

ll f(ll b, ll n){
  if(n < b) return n;
  else return f(b, floor(n/b)) + (n % b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, s;
  cin >> n >> s;
  if(n == s){
    cout << n+1 << endl;
    return 0;
  }

  for (ll b = 2; b*b <= n; b++) {
    if(f(b, n) == s){
      cout << b << endl;
      return 0;
    }
  }

  ll res = LLONG_MAX;
  bool flag = false;
  for (ll p = 1; p*p <= n; p++) {
    if((n-s)%p != 0) continue;
    ll b = (n-s)/p + 1;
    if(b >= 2 && f(b, n) == s){
      res = min(res, b);
      flag = true;
    }
  }

  res = flag ? -1 : res;
  cout << -1 << endl;
}
