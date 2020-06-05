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
  int n, m, l, p, q, r;
  cin >> n >> m >> l >> p >>  q >> r;
  int res = (n / p) * (m / q) * (l / r);
  chmax(res, (n / p) * (m / r) * (l / q));
  chmax(res, (n / q) * (m / r) * (l / p));
  chmax(res, (n / q) * (m / p) * (l / r));
  chmax(res, (n / r) * (m / p) * (l / q));
  chmax(res, (n / r) * (m / q) * (l / p));
  cout << res << endl;
}
