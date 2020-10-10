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
  int a, b;
  // cin >> a >> b;
  cin >> b >> a;
  string tmp = "";
  int l = 100;
  rep(i, l) tmp += ".";
  vector<string> v(l, tmp);

  for (int i = 0; i < l; i+=2) {
    for (int j = 0; j < l/2-1; j+=2) {
      if(a > 1) v[i][j] = '#';
      a--;
    }
  }

  for (int i = 0; i < l; i++) {
    for (int j = l/2; j < l; j++) {
      v[i][j] = '#';
    }
  }

  for (int i = 0; i < l; i+=2) {
    for (int j = l-1; j > l/2; j-=2) {
      if(b > 1) v[i][j] = '.';
      b--;
    }
  }

  cout << l << ' ' << l << endl;

  rep(i, l) cout << v[i] << endl;
}
