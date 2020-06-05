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
  int n, m;
  cin >> n >> m;
  vector<string> v2(n);
  vector<vector<int>> v(n, vector<int> (m));

  rep(i, n) cin >> v2[i];

  rep(i, n) rep(j, m){
    v[i][j] = v2[i][j] - '0';
  }

  vector<vector<int>> res(n, vector<int> (m));
  for (int i = 1; i < n-1; ++i) {
    for (int j = 1; j < m-1; ++j) {
      int num = min({v[i+1][j], v[i-1][j], v[i][j+1], v[i][j-1]});
      res[i][j] += num;
      v[i+1][j] -= num;
      v[i-1][j] -= num;
      v[i][j+1] -= num;
      v[i][j-1] -= num;
    }
  }

  rep(i, n) {
    rep(j, m) cout << res[i][j];
    cout << endl;
  }
}
