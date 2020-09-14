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

int h, w;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w;
  ll now = 0, dis=0;
  for (int i = 0; i < h; ++i) {
    int from, to;
    cin >> from >> to;
    from--;to--;
    ll res = 0;
    bool flag = res == -1;
    if(from > now && !flag && now < w-1){
      res = dis+1;
    }else if(!flag && now < w-1){
      res = dis+max(0ll, to-now)+2;
      now = to+1;
    }else{
      res = -1;
      now = INT_MAX;
    }

    cout << res << endl;
    dis = res;
  }
}
