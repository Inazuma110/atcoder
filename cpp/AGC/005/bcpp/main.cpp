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
  ll n;
  cin >> n;
  map<ll, ll> mp;
  for (ll i = 1; i <= n; i++) {
    ll tmp;
    cin >> tmp;
    mp[tmp] = i;
  }

  set<ll> used = {0, n+1};
  ll res = 0;
  for (ll i = 1; i <= n; i++) {
    auto it = used.lower_bound(mp[i]);
    ll l = *it;
    ll r = *(--it);
    res += i * (mp[i]-l) * (r-mp[i]);
    used.insert(mp[i]);
  }

  cout << res << endl;
}
