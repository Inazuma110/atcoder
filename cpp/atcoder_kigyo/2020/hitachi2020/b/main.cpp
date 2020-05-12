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
  ll a, b, m;
  cin >> a >> b >> m;
  vector<ll> va(a), vb(b);
  rep(i, a) cin >> va[i];
  rep(i, b) cin >> vb[i];
  ll res = LLONG_MAX;
  rep(i, m){
    int x, y, c;
    cin >> x >> y >> c;
    x--;y--;
    res = min(res, va[x]+vb[y]-c);
  }
  sort(ALL(va));
  sort(ALL(vb));
  res = min(res, va[0]+vb[0]);
  cout << res << endl;
}
