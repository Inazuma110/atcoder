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
  ll n;
  cin >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(all(v));

  ll now = 1;
  ll now_size = v[0];
  ll res = 1;
  ll start = 0;
  while(true) {
    if(v[now] <= now_size * 2) {
      now_size += v[now];
    }else{
      now_size += v[now];
      start = now;
    }
    if(now == n-1){
      res = n - start;
      break;
    }
    now++;
  }

  cout << res << endl;


}

