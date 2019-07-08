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
  ll l, r;
  cin >> l >> r;
  ll minv = LLONG_MAX;
  for (ll i = l; i <= l+2019; i++) {
    if(i == r+1) break;
    for (ll j = i+1; j <= i+1+2019; j++) {
      // cout << j << endl;
      if(j == r+1) break;
      minv = min((i*j) % 2019, minv);
    }

    // cout << i << minv << endl;
  }

  cout << minv << endl;
}
    // if(minv == 0){
    //   if(r <= minv + 2019){
    //     cout << 0 << endl;
    //     return 0;
    //   }else if(r == minv){
    //     cout << ((l % 2019) * ((l + 1) % 2019)) % 2019 << endl;
    //     return 0;
    //   }
    // }
