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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll res = INT_MAX;
  for (int i = 1; i < n; i++) {
    ll sum1 = 0, sum2 = 0;
    for (int j = 0; j < i; j++) {
      sum1 += v[j];
    }
    for (int j = i; j < n; j++) {
      sum2 += v[j];
    }
    // cout << sum1 << endl;
    // cout << sum2 << endl;
    res = min(res, abs(sum1 - sum2));
  }

  cout << res << endl;
}
