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

struct Edge {
  long long to;
  long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
const long long INF = 1LL << 60;


/* dijkstra(G,s,dis,prev)
   入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
   計算量：O(|E|log|V|)
   副作用：dis, prevが書き換えられる
   */
void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<int> &prev) {
  int N = G.size();
  dis.resize(N, INF);
  prev.resize(N, -1); // 初期化
  priority_queue<P, vector<P>, greater<P>> pq;
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    int v = p.second;
    if (dis[v] < p.first) {
      continue;
    }
    for (auto &e : G[v]) {
      if (dis[e.to] > dis[v] + e.cost) {
        dis[e.to] = dis[v] + e.cost;
        prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
        pq.emplace(dis[e.to], e.to);
      }
    }
  }
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
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--;t--;
  vector<vector<Edge>> g(n);
  rep(i, m){
    int from, to, cost;
    cin >> from >> to >> cost;
    from--;to--;
    g[from].push_back({to, cost});
    g[to].push_back({from, cost});
  }
  vector<ll> dist1;
  vector<int> prev1;
  vector<ll> dist2;
  vector<int> prev2;
  dijkstra(g, s, dist1, prev1);
  dijkstra(g, t, dist2, prev2);

  for (int i = 0; i < n; ++i) {
    if(dist1[i] == INF || dist2[i] == INF) continue;
    if(dist1[i] == dist2[i]){
      cout << i+1 << endl;
      exit(0);
    }
  }
  cout << -1 << endl;
}
