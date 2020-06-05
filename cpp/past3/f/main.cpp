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
  ll src, to;
  T cost;

  edge(ll to, T cost) : src(-1), to(to), cost(cost) {}

  edge(ll src, ll to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const ll &x) {
    to = x;
    return *this;
  }

  operator ll() const { return to; }
};

const auto INF = numeric_limits<ll>::max();

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< ll > >;
template< typename T >
using Matrix = vector< vector< T > >;
template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, ll s) {
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, ll >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    ll idx;
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

ll norm(ll y, ll x){
  y += 210; x += 210;
  return x + y*420;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, x, y;
  cin >> n >> x >> y;
  WeightedGraph<ll> g(550 * 550);

  ll dx[] = {1, 0, -1, 1, -1, 0};
  ll dy[] = {1, 1, 1, 0, 0, -1};

  set<ll> s;
  rep(i, n){
    ll x, y;
    cin >> x >> y;
    s.insert(norm(y, x));
  }

  rep(i, 500){
    rep(j, 500){
      // if(s.count(norm(i, j)) == 1){
      //   cout << i << ' ' << j  << ' ' << norm(i, j) << endl;
      // }
      if(s.count(norm(i, j)) >= 1) continue;
      rep(k, 6){
        ll ny = i + dy[k];
        ll nx = j + dx[k];
        ll from = norm(i, j);
        ll to = norm(ny, nx);
        if(s.count(to) >= 1) continue;
        if(s.count(from) >= 1) continue;

        g[from].push_back({to, 1});
        g[to].push_back({from, 1});
      }
    }
  }

  auto res = dijkstra(g, norm(0, 0));
  if(res[norm(y, x)] == INF) cout << -1 << endl;
  else cout << res[norm(y, x)] << endl;
}
