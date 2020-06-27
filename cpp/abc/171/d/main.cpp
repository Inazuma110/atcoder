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
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> mp;
  ll res = 0;
  rep(i, n) cin >> v[i];
  rep(i, n) mp[v[i]]++;
  rep(i, n) res += v[i];
  int q;
  cin >> q;
  vector<p> qs(q);
  rep(i, q) cin >> qs[i].first >> qs[i].second;

  for (int i = 0; i < q; ++i) {
    ll from = qs[i].first;
    ll to = qs[i].second;
    ll tmp1 = mp[from] * from;
    ll tmp2 = mp[from] * to;
    res += tmp2 - tmp1;
    cout << res << endl;
    mp[to] += mp[from];
    mp[from] = 0;
    // print(mp);
  }
}