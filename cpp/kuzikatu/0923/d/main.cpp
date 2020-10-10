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
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> a(m);
  a[0] = x;
  vector<ll> used(m);
  used[x] = true;
  ll start = 0, end = 0;
  map<ll, ll> when;
  ll sum = a[0];
  ll syu = 0;

  for (int i = 1; ; ++i) {
    ll tmp = (a[i-1] * a[i-1]) % m;
    if(used[tmp]) {
      end = i-1;
      start = when[tmp];
      syu = sum;
      break;
    }
    a[i] = tmp;
    used[tmp] = true;
    when[tmp] = i;
    sum += tmp;
  }

  // print(a);
  // cout << start << endl;
  // cout << end << endl;
  rep(i, start) syu -= a[i];
  ll res = sum - syu;
  ll cnt = start;
  n -= cnt;
  res += syu * (n / (end-start+1));
  n %= (end-start+1);
  rep(i, n) res += a[start+i];

  cout << res << endl;
}
