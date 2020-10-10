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
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  sort(ALL(v));
  ll res = 0;
  rep(i, n){
    for (int j = i+1; j < n; ++j) {
      for (int k = j+1; k < n; ++k) {
        if(v[i] == v[j] || v[i] == v[k] || v[j] == v[k]) continue;
        if(v[i] + v[j] > v[k] && v[i] + v[k] > v[j] && v[j] + v[k] > v[i]) res++;
      }
    }
  }

  cout << res << endl;
}
