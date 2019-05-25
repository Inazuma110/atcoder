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
typedef pair<ll, ll> p;


int main(){
  int n, m;
  cin >> n >> m;
  vector<p> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }

  ll res = 0;
  sort(all(v));

  for (int i = 0; i < n; i++) {
    ll val = v[i].first;
    ll num = v[i].second;
    if(num < m){
      res += val * num;
      m -= num;
    }else{
      res += m * val;
      break;
    }
  }

  cout << res << endl;

}
