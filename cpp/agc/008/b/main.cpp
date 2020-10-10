#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  vector<ll> sum(n+1, 0);
  // ll maxv = -LLONG_MAX;
  // ll maxv_index = -1;
  // ll minv = LLONG_MAX;
  // ll minv_index = -1;
  ll res = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum[i+1] = sum[i] + v[i];
  }

  for (int i = 0; i <= n+k; i+=k) {
    cout << i << endl;
    if(i+1+k <= n){
      if(sum[i+1+k] - sum[i+1] > 0) res += sum[i+1+k] - sum[i+1];
    }else{
      if(sum[n] - sum[i+1] > 0) res += sum[n] - sum[i+1];
      break;
    }
  }
  cout << res << endl;
}
