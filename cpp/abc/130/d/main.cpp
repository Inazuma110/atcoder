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
  ll n, k;
  cin >> n >> k;
  vector<int> v(n);
  vector<ll> sum(n+1);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum[i+1] = sum[i] + v[i];
  }

  ll res = 0;
  for (int i = 1; i < n+1; i++) {
    if(sum[i] >= k){
      ll tmp = sum[i] - k;
      int x = upper_bound(ALL(sum), tmp) - sum.begin();
      if(x <= i){
        res += x;
      }
    }
  }
  cout << res << endl;
}
