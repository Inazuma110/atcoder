#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<ll, ll> p;

int main(){
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  // sort(all(v));
  ll near_c = INT_MAX, near_b = INT_MAX, near_a = INT_MAX;
  ll near_c_index = -1, near_b_index = -1, near_a_index = -1;

  ll res = 0;
  for (ll i = 0; i < n; i++) {
    if(v[i] <= c && c - v[i] < abs(c - near_c)){
      near_c = v[i];
      near_c_index = i;
    }
  }
  for (ll i = 0; i < n; i++) {
    if(v[i] <= b && b - v[i] < abs(b - near_b) && i != near_c_index){
      near_b = v[i];
      near_b_index = i;
    }
  }
  for (ll i = 0; i < n; i++) {
    if(v[i] <= a && a - v[i] < abs(a - near_a) && i != near_c_index && i != near_b_index){
      near_a = v[i];
      near_a_index = i;
    }
  }

  set<ll> use_index;

  for (ll i = 0; i < n; i++) {
    if(i == near_c_index || near_b_index == i ||  i == near_a_index)
      continue;
    if(use_index.count(i) == 1) continue;
    if(abs(c - near_c) <= 10) break;
    if(c-near_c > abs(c-(near_c+v[i]))+10 && v[i] > 10)
    {
      res += 10;
      near_c += v[i];
      use_index.insert(i);
    }
  }
  res += abs(c - near_c);

  for (ll i = 0; i < n; i++) {
    if(i == near_c_index || near_b_index == i ||  i == near_a_index)
      continue;
    if(use_index.count(i) == 1) continue;
    if(abs(b - near_b) <= 10) break;
    if(b-near_b > abs(b-(near_b+v[i]))+10 && v[i] > 10)
    {
      res += 10;
      near_b += v[i];
      use_index.insert(i);
    }
  }
  res += abs(b - near_b);

  ///////////
 for (ll i = 0; i < n; i++) {
    if(i == near_c_index || near_b_index == i ||  i == near_a_index)
      continue;
    if(use_index.count(i) == 1) continue;
    if(abs(a - near_a) <= 10) break;
    if(a-near_a > abs(a-(near_a+v[i]))+10 && v[i] > 10)
    {
      res += 10;
      near_a += v[i];
      use_index.insert(i);
    }
  }
  res += abs(a - near_a);

  cout << res << endl;
}
