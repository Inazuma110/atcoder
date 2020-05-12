#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
//
// using boost::multiprecision::cpp_int;
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
  rep(i, n) cin >> v[i];
  vector<int> maxvs(n, -1);
  vector<int> minvs(n, INT_MAX);
  int maxv = INT_MIN;
  int minv = INT_MAX;
  for (int i = 0; i < n; i++) {
    minv = min(minv, v[i]);
    minvs[i] = minv;
  }
  int res = INT_MIN;
  for (int i = n-2; i >= 0; i--) {
    maxv = max(maxv, v[i+1]);
    res = max(res, maxv-minvs[i]);
  }
  cout << res << endl;
}
