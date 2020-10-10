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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if((a <= c && b >= c) || (a <= c && d <= b)){
    cout << "Yes" << endl;
    return 0;
  }
  swap(a, c);
  swap(b, d);
  if((a <= c && b >= c) || (a <= c && d <= b)){
    cout << "Yes" << endl;
  }else cout << "No" << endl;
}