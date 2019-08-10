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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  vector<ll> sum(n+1);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum[i+1] = sum[i] + v[i];
  }
  ll res = 0;
  for (int i = 0; i + k < n + 1 ; i++) {
    res += sum[i + k] - sum[i];
    // cout << sum[i+k] - sum[i] << endl;
  }
  cout << res << endl;
}
