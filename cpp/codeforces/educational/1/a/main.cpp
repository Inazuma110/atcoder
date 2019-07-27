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

ll solve(){
  ll n;
  cin >> n;
  ll sum = double((1 + n) * n) / 2.0;
  vector<ll> v(100);
  for (int i = 0; i < 100; i++) {
    v[i] = (1 << i);
    if(v[i] > n) break;
    sum -= v[i] * 2;
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << endl;
  }
}
