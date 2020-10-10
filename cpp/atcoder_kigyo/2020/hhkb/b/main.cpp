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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  rep(i, h) cin >> v[i];

  ll res = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w-1; ++j) {
      if(v[i][j] == '.' && v[i][j+1] == '.') res++;
    }
  }

  for (int j = 0; j < w; ++j) {
    for (int i = 0; i < h-1; ++i) {
      if(v[i][j] == '.' && v[i+1][j] == '.') res++;
    }
  }

  cout << res <<endl;
}
