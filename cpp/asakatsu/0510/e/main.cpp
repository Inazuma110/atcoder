#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <queue>

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
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, u, v;
  cin >> n >> u >> v;
  u--; v--;
  WeightedGraph<int> tree(n);
  rep(i, n-1){
    int from, to;
    cin >> from >> to;
    from--;to--;
    auto e = edge<int>(to, 1);
    tree[from].push_back(e);
    e = edge<int>(from, 1);
    tree[to].push_back(e);
  }

  // takahashi
  auto res1 = dijkstra(tree, u);
  // aoki
  auto res2 = dijkstra(tree, v);
  priority_queue<p> pq;
  for(int i = 0; i < n; i++) pq.push({res2[i], i});
  int res = 0;
  // print(res1);
  // print(res2);
  rep(i, n){
    // aoki
    int d = pq.top().first;
    int p = pq.top().second;
    pq.pop();
    if(d <= res1[p]) continue;
    chmax(res, d-1);
    // if((res2[p] - res1[p]) % 2 == 0) chmax(res, res1[p]-1);
    // else chmax(res, res1[p]);
  }
  cout << res << endl;

}
