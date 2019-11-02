#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
//
// using boost::multiprecision::cpp_int;
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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  sort(ALL(v));
  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      ll tmp1 = abs(v[i] - v[j]);
      ll tmp2 = v[i] + v[j];
      ll index1 = upper_bound(ALL(v), tmp1) - v.begin();
      ll index2 = lower_bound(ALL(v), tmp2) - v.begin();
      index2--;
      ll count = 0;
      if(index1 <= i && i <= index2) count++;
      if(index1 <= j && j <= index2) count++;
      // cout << index1 << ' ' << index2 << endl;
      // cout << count << endl;
      res += max(0ll, index2 - index1 + 1ll - count);
    }
  }

  cout << res / 3 << endl;
}
