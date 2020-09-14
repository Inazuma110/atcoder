#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

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
using Graph = vector<vector<p>>;
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
      if (dis[e.first] > dis[v] + e.second) {
        dis[e.first] = dis[v] + e.second;
        prev[e.first] = v; // 頂点 v を通って e.to にたどり着いた
        pq.emplace(dis[e.first], e.first);
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
int h, w, ch, cw, dh, dw;

ll f(int y, int x) {
  return y*w + x;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w >> ch >> cw >> dh >> dw;
  ch--;cw--;dh--;dw--;
  vector<string> v(h);
  rep(i, h) cin >> v[i];
  Graph g(h*w);
  rep(i, h) rep(j, w){
    if(v[i][j] == '#') continue;
    for (int k1 = -2; k1 <= 2; k1++) {
      for (int k2 = -2; k2 <= 2; k2++) {
        if(k1 == 0 && k2 == 0) continue;
        int ny = i+k1;
        int nx = j+k2;
        if(ny >= h || nx >= w || ny < 0 || nx < 0) continue;
        if(v[ny][nx] == '#') continue;
        // cout << i << ' ' << j  << ' ' << k1 << ' ' << k2 << endl;
        // cout << f(i, j) << ' ' << f(ny, nx) << endl;
        if((k1==1&&k2==0) || (k1==-1&&k2==0) || (k1==0&&k2==1) || (k1==0&&k2==-1)){
          g[f(i, j)].push_back({f(ny, nx), 0});
        }else{
          g[f(i, j)].push_back({f(ny, nx), 1});
        }
      }
    }
  }

  vector<ll> dist;
  vector<int> prev;

  // dijkstra(g, f(0, 0), dist, prev);
  dijkstra(g, f(ch, cw), dist, prev);

  ll res = dist[f(dh, dw)];
  if(res == INF) cout << -1 << endl;
  else cout << res << endl;
}
