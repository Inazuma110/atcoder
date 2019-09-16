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
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vector<p> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  ll res = 0;
  vector<int> light(n);
  rep(i, n){
    light[i] = s[i] - '0';
    if(light[i] == 1) res++;
  }

  for (int i = 1; i <= 1000000; i++) {
    ll count = 0;
    for (int j = 0; j < n; j++) {
      int ai = v[j].first;
      int bi = v[j].second;
      if(((i - bi) >= 0) && ((i - bi) % ai == 0)){
        light[j]++;
        light[j] %= 2;
      }
      if(light[j] == 1) count++;
    }
    res = max(res, count);
  }
  cout << res << endl;
}
