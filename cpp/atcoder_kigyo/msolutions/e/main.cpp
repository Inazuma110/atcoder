#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000003

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    ll xq, dq, nq;
    ll n = nq;
    cin >> xq >> dq >> nq;
    ll an = xq + (nq-1) * dq;
    ll res = xq + (an % MOD);
    cout << res << endl;
    res *= nq;
    res /= 2;
    res %= MOD;
    cout << res << endl;

  }
}
