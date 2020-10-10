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

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
template< typename T >
void warshall_floyd(Matrix< T > &g, T INF) {
  for(int k = 0; k < g.size(); k++) {
    for(int i = 0; i < g.size(); i++) {
      for(int j = 0; j < g.size(); j++) {
        if(g[i][k] == INF || g[k][j] == INF) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> v(r);
  rep(i, r) cin >> v[i], v[i]--;
  vector<vector<ll>> dp((1ll<<8), vector<ll>(n+3, 0));
  Matrix<ll> g(n, vector<ll>(n, INT_MAX));
  rep(i, n) g[i][i] = 0;
  rep(i, m){
    int from, to, cost;
    cin >> from >> to >> cost;
    from--; to--;
    g[from][to] = cost;
    g[to][from] = cost;
  }

  warshall_floyd(g, (ll)INT_MAX);
  ll res = LLONG_MAX;
  // print(g);
  sort(ALL(v));
  do {
    ll count = 0;
    for (int i = 0; i < r-1; ++i) {
      count += g[v[i]][v[i+1]];
    }
    // print(v);
    // cout << count << endl;
    chmin(res, count);
  }while (next_permutation(ALL(v)));

  cout << res << endl;
}
