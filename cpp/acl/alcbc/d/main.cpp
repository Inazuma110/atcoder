#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
using namespace atcoder;

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

int op(int a, int b){return max(a, b);}
int e(){ return 0;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n+10, vector<int>(2));
  segtree<int, op, e> seg(300000+10);
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    // seg.set(a[i], 1);
  }

  dp[1][1] = 1;
  for (int i = 1; i < n+1; ++i) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    dp[i][1] = seg.prod(max(0, a[i-1]-k), min(300000+10, a[i-1]+k+1)) + 1;
    seg.set(a[i-1], dp[i][1]);
  }

  // print(dp);
  cout << max(dp[n][0], dp[n][1]) << endl;
}
