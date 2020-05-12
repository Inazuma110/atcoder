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
  int n, m, s;
  cin >> n >> m >> s;
  vector<vector<int>> unchin(n, vector<int>(n, INT_MAX/2));
  vector<vector<int>> time(n, vector<int>(n, INT_MAX/2));
  rep(i, n){
    unchin[i][i] = 0;
    time[i][i] = 0;
  }
  vector<int> rate(n), rate_time(n);
  rep(i, m){
    int from, to, a, b;
    cin >> from >> to >> a >> b;
    from--;to--;
    unchin[from][to] = a;
    time[from][to] = b;
    unchin[to][from] = a;
    time[to][from] = b;
  }
  rep(i, n){
    cin >> rate[i] >> rate_time[i];
  }
}
