#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;

p factoring(ll a){
  vector<pair<ll, ll>> v;
  ll res = 1;
  for (ll i = 2; i <= pow(10, 9); i++) {
    if(a % i == 0){
      cout << i << endl;
      ll count = 0;
      while(a % i == 0){
        count++;
        a /= i;
        res *= i;
        if(a <= pow(10, 9)) break;
      }
      if(a <= pow(10, 9)) break;
      v.push_back({i, count});
    }
  }
  return {res, a};
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll s;
  cin >> s;
  if(s <= pow(10, 9)){
    cout << 0 << ' ' << 0 << ' ' << s << ' ' << 0 << ' ' << s << ' ' << 1 << endl;
    return 0;
  }
  p tmp = factoring(s);
  // print(tmp.first);
  // print(tmp.second);
  cout << 0 << ' ' << 0 << ' ' << tmp.first << ' ' << 0 << ' ' << tmp.first << ' ' << tmp.second << endl;
}
