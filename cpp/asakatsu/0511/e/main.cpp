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
vector<int> pre;

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
      pre[e.to] = idx;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

/* get_path(prev, t)
    入力：dijkstra で得た prev, ゴール t
    出力： t への最短路のパス
*/
vector<int> get_path(const vector<int> &prev, int t) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    return path;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, g;
  cin >> s >>g;
  int n;
  cin >> n;
  vector<string> v(n);
  rep(i, n) cin >> v[i];
  int m = s.size();
  pre = vector<int> (n+2);

  auto check = [&](string s, string t){
    int count = 0;
    for (int i = 0; i < m; ++i) {
      if(s[i] != t[i]) count++;
    }
    return count;
  };

  WeightedGraph<int> graph(n+2);
  if(s == g){
    cout << 0 << endl;
    cout << s << endl;
    cout << g << endl;
    return 0;
  }

  rep(i, n){
    int count = check(v[i], s);
    if(count == 1) {
      graph[0].push_back(edge<int>(i+1, 1));
      graph[i+1].push_back(edge<int>(0, 1));
    }
    count = check(v[i], g);
    if(count == 1) {
      graph[n+1].push_back(edge<int>(i+1, 1));
      graph[i+1].push_back(edge<int>(n+1, 1));
    }
  }

  rep(i, n) {
    if(v[i] == s || v[i] == g) continue;
    rep(j, n){
      if(i <= j) continue;
      if(v[j] == s || v[j] == g) continue;
      int count = check(v[i], v[j]);
      if(count == 1){
        graph[i+1].push_back(edge<int>(j+1, 1));
        graph[j+1].push_back(edge<int>(i+1, 1));
      }
    }
  }
  if(check(s, g) == 1){
    graph[0].push_back(edge<int>(n+1, 1));
    graph[n+1].push_back(edge<int>(0, 1));
  }

  auto ds = dijkstra(graph, 0);
  pre[0] = -1;
  auto path = get_path(pre, n+1);
  // print(path);
  // print(pre);
  // print(ds);
  if(ds[n+1] == INT_MAX){
    cout << -1 << endl;
    return 0;
  }
  cout << ds[n+1]-1 << endl;
  cout << s << endl;
  for (int i = 1; i < int(path.size())-1; ++i) {
    // cout << path[i] -1 << endl;
    cout << v[path[i]-1] << endl;
  }
  cout << g << endl;
}

