#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

long long comb(ll n, ll r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    ll i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mp[v[i]]++;
  }
  sort(rall(v));
  ll sum = 0;
  ll big_num = 0;
  for (int i = 0; i < a; i++) {
    sum += v[i];
    if(v[i] > v[a-1]) big_num++;
  }

  long double ave = double(sum) / double(a);
  printf("%LF\n",ave);

  ll res = 0;
  if(a <= mp[v[0]]){
    for (int i = a; i <= mp[v[0]] && i <= b; i++) {
      res += comb(mp[v[0]], i);
    }
  }else if(mp[v[a-1]] >= 2){
    res += comb(mp[v[a-1]], a-big_num);
  }else res++;

  cout << res << endl;
}
