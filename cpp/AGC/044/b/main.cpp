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

int n;
int dx[] = {1, 0};
int dy[] = {0, 1};

struct Tree {
  ll node_num;
  ll edge_num;
  ll diameter = -1;
  ll far_index = -1;
  vector<vector<ll>> to;
  vector<bool> visited;
  vector<int> depth;

  Tree(ll nn) : node_num(nn){
    edge_num = node_num - 1;
    to = vector<vector<ll>> (node_num);
    visited = vector<bool> (node_num, false);
    depth = vector<int> (node_num);
  }


  pair<ll, ll> get_far(ll from, ll d){
    visited[from] = true;
    for(auto a : to[from]){
      if(!visited[a]){
        get_far(a, d+1);
      }
    }
    if(diameter < d){
      diameter = d;
      far_index = from;
    }
    return {far_index, diameter};
  }

  ll get_diameter(ll from){
    pair<ll, ll> i_and_d = get_far(0, 0);
    init();
    diameter = get_far(i_and_d.first, 0).second;
    init();
    return diameter;
  }

  void init(){
    visited = vector<bool> (node_num, false);
  }

  int set_depth(int from, int d){
    visited[from] = true;
    for(auto a : to[from]){
      if(!visited[a]) set_depth(a, d+1);
    }
    return depth[from] = d;
  }
};

int norm(int y, int x){
  return x + y*n;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<p> o(n*n);
  vector<vector<int>> v(n, vector<int> (n));
  Tree tree(n*n+0);
  rep(i, n){
    rep(j, n){
      cin >> o[norm(i, j)].second;
      o[norm(i, j)].second--;
      o[norm(i, j)].first = norm(i, j);
    }
  }

  // WeightedGraph<int> g(n*n+1);
  //
  // rep(i, n){
  //   g[norm(0, i)].push_back({n*n, 0});
  //   g[n*n].push_back({norm(0, i), 0});
  //   g[norm(n-1, i)].push_back({n*n, 0});
  //   g[n*n].push_back({norm(n-1, i), 0});
  // }
  // for (int i = 1; i < n-1; ++i) {
  //   g[norm(i, 0)].push_back({n*n, 0});
  //   g[n*n].push_back({norm(i, 0), 0});
  //   g[norm(i, n-1)].push_back({n*n, 0});
  //   g[n*n].push_back({norm(i, n-1), 0});
  // }
  //
  //
  // rep(i, n){
  //   rep(j, n){
  //     v[i][j] = min({n-1-i, n-1-j, i, j});
  //     int from = norm(i, j);
  //     rep(k, 2){
  //       int ny = i + dy[k];
  //       int nx = j + dx[k];
  //       if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
  //       int to = norm(ny, nx);
  //       g[from].push_back({to, 1});
  //       g[to].push_back({from, 1});
  //       tree[from].push_back(to);
  //       tree[to].push_back(from);
  //     }
  //   }
  // }
  // ll count = 0;
  // vector<int> visited(n*n);
  //
  // rep(i, n) rep(j, n){
  //   int ty = o[norm(i, j)].second / n;
  //   int tx = o[norm(i, j)].second % n;
  //   int s = o[norm(i, j)].second;
  //   queue<p> q;
  //   q.push({s, 0});
  //   while(!q.empty()){
  //     int now = q.front().first;
  //     int d = q.front().second;
  //   }
  //
  // }
  //
  // // int dx2[] = {1, -1, 0, 0};
  // // int dy2[] = {0, 0, 1, -1};
  //
  // // for(auto a : g) cout << a.size() << endl;
  // // auto res = dijkstra(g, n*n);
  // // print(res);
  //
  // // rep(i, n){
  // //   rep(j, n){
  // //     int ty = o[norm(i, j)].second / n;
  // //     int tx = o[norm(i, j)].second % n;
  // //     count += res[norm(ty, tx)];
  // //     // for(auto &e : g[norm(ty, tx)]){
  // //     //   if(e.cost >= 1) e.cost--;
  // //     // }
  // //     // rep(k, 4){
  // //     //   int ny2 = ty+dy2[k], nx2 = tx+dx2[k];
  // //     //   if(ny2 < 0 || ny2 >= n || nx2 < 0 || nx2 >= n) continue;
  // //     //   for(auto &e : g[norm(ny2, nx2)]){
  // //     //     if(e.cost >= 1 && e.to == norm(ty, tx)) e.cost--;
  // //     //   }
  // //     // }
  // //     // cout << res[norm(ty, tx)] << endl;
  // //   }
  // // }
  //
  // cout << count << endl;

}
