#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
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
  ll n, d, a;
  cin >> n >> d >> a;
  vector<p> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  vector<ll> max_j(n, -1);
  int next = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = next; j < n; ++j) {
      ll p = v[j].first;
      // cout << p << endl;
      if(p >= v[i].first + 2ll * d) {
        max_j[i] = (p == v[i].first + 2 * d) ? j : j-1;
        next = (p == v[i].first + 2 * d) ? j+1 : j;
        break;
      }
    }
    // cout << "===" << endl;
    if(max_j[i] == -1){
      for (int j = i; j < n; ++j) {
        max_j[i] = n-1;
      }
      break;
    }
  }
  // print(max_j);

  ll res = 0;
  vector<ll> imos(n+3);
  for (int i = max_j[0]; i < n; ++i) {
    ll h = max(0ll, v[i].second - a * imos[i]);
    // ll x = v[i].first - 1;
    ll num = (h + a - 1) / a;
    res += num;
    // cout << h << endl;
    // cout << num << endl;
    imos[i] += num;
    imos[max_j[i]+1] -= num;
    imos[i+1] += imos[i];
    // print(imos);
  }

  cout << res << endl;
}
