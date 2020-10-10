#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>
#include <cstdlib>

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
  int n;
  cin >> n;
  vector<string> v(n);
  vector<vector<int>> g(n);
  Matrix<int> m(n, vector<int>(n, (1<<30)));
  rep(i, n){
    cin >> v[i];
    for (int j = 0; j < n; ++j) {
      if(v[i][j] == '1'){
        g[i].push_back(j);
        m[i][j] = 1;
      }
    }
    m[i][i] = 0;
  }
  vector<int> colors(n, -1);
  vector<int> visit(n);
  queue<p> q;
  q.push({0, 0});
  colors[0] = 0;

  while(!q.empty()){
    int from = q.front().first;
    int c = q.front().second;
    q.pop();

    for (int i = 0; i < g[from].size(); ++i) {
      int to = g[from][i];
      if(colors[to] == -1){
        colors[to] = !c;
      }else if(colors[to] == c){
        cout << -1 << endl;
        exit(0);
      }
      if(!visit[to]) visit[to] = 1, q.push({to, !c});

    }
  }

  warshall_floyd(m, (1<<30));
  int res = 0;
  rep(i, n) rep(j, n) chmax(res, m[i][j]);

  cout << res+1 << endl;

}
