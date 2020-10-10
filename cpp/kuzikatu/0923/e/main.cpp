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
/* warshall_floyd(dist,prev)
    入力：初期化した dist, prev
    計算量：O(|V|^3)
    副作用：dis[i][j]にiからjへの最短路のコストを格納、prev[i][j]にiからjへの最短路でのjの1つ前の点を格納
*/
void warshall_floyd(vector<vector<long long>> &dist, vector<vector<long long>> &prev) {
  int V = dist.size();
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          prev[i][j] = prev[k][j];
        }
      }
    }
  }
}

/* get_path(prev, s, t)
   入力：warshall_floyd で得た prev, スタート s, ゴール t
   出力：s から t への最短路のパス
   */
vector<int> get_path(const vector<vector<long long>> &prev, int s, int t) {
  vector<int> path;
  for (int cur = t; cur != s; cur = prev[s][cur]) {
    path.push_back(cur);
  }
  path.push_back(s);
  reverse(path.begin(), path.end());
  return path;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> dist(n, vector<ll>(n, INT_MAX)), prev(n, vector<ll>(n));
  rep(i, n) dist[i][i] = 0;
  vector<vector<int>> used(n, vector<int>(n, -1));
  rep(i, m){
    int from, to, cost;
    cin >> from >> to >> cost;
    from--; to--;
    dist[from][to] = dist[to][from] = cost;
    prev[from][to] = from;
    prev[to][from] = to;
    used[from][to] = 0;
    used[to][from] = 0;
  }

  warshall_floyd(dist, prev);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if(i == j) continue;
      auto path = get_path(prev, i, j);
      rep(k, (int)path.size()-1) used[path[k]][path[k+1]] = true;
    }
  }

  ll res = 0;
  rep(i, n) rep(j, n) if(i!=j && used[i][j] != -1) res += !used[i][j];
  res /= 2;

  cout << res << endl;


}
