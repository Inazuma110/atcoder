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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  ll res = 0;

  for (int l = 0; l <= k; l++) {
    for (int r = 0; l + r <= k; r++) {
      if(l + r > n) continue;
      int d = k - l - r;
      ll count = 0;
      vector<int> tmp;
      for (int i = 0; i < l; i++) {
        count += v[i];
        tmp.push_back(v[i]);
      }
      for (int i = n-r; i < n; i++) {
        count += v[i];
        tmp.push_back(v[i]);
      }
      sort(ALL(tmp));
      for (int i = 0; i < d; i++) {
        if(i >= int(tmp.size())) break;
        if(tmp[i] > 0) break;
        count -= tmp[i];
      }
      res = max(res, count);
    }
  }
  cout << res << endl;
}
