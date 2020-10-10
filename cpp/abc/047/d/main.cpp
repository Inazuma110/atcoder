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
  ll n, t;
  cin >> n >> t;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];

  ll minv = INT_MAX;
  ll maxv = -1;
  map<int, int> p;
  vector<ll> maxvs(n);

  for (int i = 0; i < n; ++i) {
    chmin(minv, v[i]);
    chmax(maxv, v[i]-minv);
    p[v[i]]=i+1;
  }

  ll res = 0;
  rep(i, n){
    if(p[v[i]+maxv] > i+1) res++;
  }

  // chmin(res, t/2);
  cout << res << endl;


}
