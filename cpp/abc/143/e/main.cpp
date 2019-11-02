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

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, l;
  cin >> n >> m >> l;
  vector<vector<ll>> v(n, vector<ll>(n, INT_MAX));
  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    from--; to--;
    v[from][to] = cost;
    v[to][from] = cost;
  }
  rep(i, n){
    rep(j, n){
      rep(k, n){
        v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
      }
    }
  }
  rep(i, n){
    rep(j, n){
      if(v[i][j] <= l) v[i][j] = 1;
      else v[i][j] = INT_MAX;
    }
  }

  rep(i, n){
    rep(j, n){
      rep(k, n){
        v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
      }
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int from, to;
    cin >> from >> to;
    from--; to--;
    if(v[from][to] >= INT_MAX) cout << -1 << endl;
    else cout << v[from][to] - 1 << endl;
  }
}
