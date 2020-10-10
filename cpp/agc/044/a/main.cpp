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
using P = pair<long, ll>;
const long long INF = 1LL << 60;


/* dijkstra(G,s,dis,prev)
   入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
   計算量：O(|E|log|V|)
   副作用：dis, prevが書き換えられる
   */
void dijkstra(const Graph &G, ll s, vector<long long> &dis, vector<ll> &prev) {
  ll N = G.size();
  dis.resize(N, INF);
  prev.resize(N, -1); // 初期化
  priority_queue<P, vector<P>, greater<P>> pq;
  dis[s] = 0;
  pq.emplace(dis[s], s);
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    ll v = p.second;
    if (dis[v] < p.first) {
      continue;
    }
    for (auto &e : G[v]) {
      if (dis[e.to] > dis[v] + e.cost) {
        // オーバーフロー対策
        if(dis[v] > INF-e.cost) dis[e.to] = INF;
        else dis[e.to] = dis[v] + e.cost;
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
vector<ll> get_path(const vector<ll> &prev, ll t) {
  vector<ll> path;
  for (ll cur = t; cur != -1; cur = prev[cur]) {
    path.push_back(cur);
  }
  reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
  return path;
}


void debug(vector<vector<Edge>> g){
  for (ll i = 0; i < ll(g.size()); ++i) {
    for(auto e : g[i]){
      cout << i << ' ' << e.to << ' ' << e.cost << endl;
    }
    cout << "====" << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll t;
  cin >> t;
  // 何倍にできるか
  ll rate[] = {2, 3, 5};

  rep(_, t){
    ll n, d;
    // rate倍にするときのコスト
    vector<ll> c(3);
    cin >> n >> c[0] >> c[1] >> c[2] >> d;

    // ダイクストラ用のグラフ．頂点数は多めに
    Graph g(500000);
    // 値が頂点で何番に対応するかを保持するmap
    map<ll, ll> mp;
    mp[n] = 1;
    ll cnt = 2;
    // dp[i] = i番目から出るエッジをすべて張ったか
    vector<ll> dp(500000);
    // グラフを構築する再帰関数 n2はみてる値
    function<void(ll)> f = [&](ll n2){
      // n2が0になったら終わり
      if(n2 == 0){
        dp[n2] = 1;
        if(mp[n2] == 0){
          mp[n2] = cnt;
          cnt++;
        }
        return;
      }

      // rateで割る
      rep(i, 3){
        // 切り捨て
        ll tmp1 = (n2 / rate[i]) * rate[i];
        // 切り上げ
        ll tmp2 = ((n2+rate[i]-1) / rate[i]) * rate[i];
        // 次に見る値
        ll next1 = tmp1/rate[i];
        ll next2 = tmp2/rate[i];
        //値と頂点番号が対応していなかったら対応付ける
        if(mp[next1] == 0) {
          mp[next1] = cnt;
          cnt++;
        }
        if(mp[next2] == 0) {
          mp[next2] = cnt;
          cnt++;
        }

        if(dp[mp[n2]]) return;

        // グラフ構築
        if((n2-next1) > LLONG_MAX/d)
          g[mp[n2]].push_back({mp[next1], abs(tmp1-n2)*d+c[i]*(next1!=0)});
        else
          g[mp[n2]].push_back({mp[next1], min(abs(tmp1-n2)*d+c[i]*(next1!=0), (n2-next1)*d)});
        f(next1);
        // 1 -> 5 -> 1 -> 5みたいなエッジのループをなくすための分岐
        if(n2 == next2) continue;
        if((n2-next2) > LLONG_MAX/d)
          g[mp[n2]].push_back({mp[next2], abs(tmp2-n2)*d+c[i]*(next2!=0)});
        else
          g[mp[n2]].push_back({mp[next2], min(abs(tmp2-n2)*d+c[i]*(next2!=0), (n2-next2)*d)});
        f(next2);
      }
      dp[mp[n2]] = 1;
    };

    f(n);
    vector<ll> dist;
    vector<ll> prev;
    dijkstra(g, mp[n], dist, prev);
    cout << dist[mp[0]] << endl;
  }

}
