#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
// using namespace atcoder;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  map<int, ll> mp;
  for (int i = 2; i <= n; ++i) {
    auto res = prime_factor(i);
    for(auto a : res){
      mp[a.first] += a.second;
    }
  }

  ll res = 0;
  for (int i = 1; i < 101; ++i) {
    for (int j = 1; j < 101; ++j) {
      for (int k = j+1; k < 101; ++k) {
        if(i == j || i == k) continue;
        vector<ll> tmp = {mp[i], mp[j], mp[k]};
        if(tmp[0] >= 2 && tmp[1] >= 4 && tmp[2] >= 4) {
          res++;
        }
      }
    }
  }

  for (int i = 1; i < 101; ++i) {
    for (int j = 1; j < 101; ++j) {
      if(i==j) continue;
      vector<ll> tmp = {mp[i], mp[j]};
      if(tmp[0] >= 2 && tmp[1] >= 24) {
        res++;
      }
      if(tmp[0] >= 4 && tmp[1] >= 14){
        res++;
      }
    }
  }

  rep(i, 101) if(mp[i] >= 74) res++;
  // print(mp);

  cout << res << endl;
}
