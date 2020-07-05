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
  ll n;
  cin >> n;
  vector<p> edges;
  ll res = 0;

  for (ll i = 1; i <= n; ++i) {
    res += i * (n-(i-1));
  }
  for (ll i = 0; i < n-1; ++i) {
    ll from, to;
    cin >> from >> to;
    from--; to--;
    edges.push_back({from, to});
    ll minv = min(from, to);
    ll maxv = max(from, to);
    res -= (minv+1) * (n-maxv);
  }
  cout << res << endl;
}
