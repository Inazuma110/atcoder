#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
// #define INF 10010010010

typedef long long ll;
typedef pair<int, int> p;

ll n, x;
vector<ll> v;
vector<ll> cost;

void init(){
  vector<ll> tmp(n, 0);
  for (ll i = 0; i < n; i++){
    cin >> tmp[i];
  }
  v = tmp;
  vector<ll> tmp2(n, LLONG_MAX);
  cost = tmp2;
}

ll calc(ll k){
  ll res = 0;
  for (ll i = 0; i < n; i++) {
    if(i - k >= 0) cost[i] = min(cost[i], v[i-k]);
    else cost[i] = min(cost[i], v[n-(k-i)]);

    // for (ll j = 0; j <= k; j++) {
    //   if(i - j >= 0){
    //     count = min(count, v[i-j]);
    //   }else{
    //     count = min(count, v[n-(j-i)]);
    //   }
    // }
    // cost[k] =
    res += cost[i];
  }
  // prll(cost);
  return res + k * x;
}


int main(){
  cin >> n >> x;
  init();

  ll res = LLONG_MAX;
  for (ll i = 0; i < n; i++) {
    // cout << calc(i) << endl;
    res = min(res, calc(i));
  }
  cout << res << endl;

}
