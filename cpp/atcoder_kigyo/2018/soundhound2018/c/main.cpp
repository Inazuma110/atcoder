#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <vector>

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

struct BipartiteMatching {
  vector< vector< int > > graph;
  vector< int > match, alive, used;
  int timestamp;

  BipartiteMatching(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

  void add_edge(int u, int v) {
    graph[u].push_back(v);
    // graph[v].push_back(u);
  }

  bool dfs(int idx) {
    used[idx] = timestamp;
    for(auto &to : graph[idx]) {
      int to_match = match[to];
      if(alive[to] == 0) continue;
      if(to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
        match[idx] = to;
        match[to] = idx;
        return true;
      }
    }
    return false;
  }

  int bipartite_matching() {
    int ret = 0;
    for(int i = 0; i < graph.size(); i++) {
      if(alive[i] == 0) continue;
      if(match[i] == -1) {
        ++timestamp;
        ret += dfs(i);
      }
    }
    return ret;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      if(i < match[i]) {
        cout << i << "-" << match[i] << endl;
      }
    }
  }
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c;
  cin >> r >> c;
  vector<string> v(r);
  rep(i, r) cin >> v[i];

  int cnt = 0;
  vector<vector<int>> id(r, vector<int>(c, -1));
  map<p, bool> used;
  rep(i, r) rep(j, c){
    if(v[i][j] == '.'){
      id[i][j] = cnt;
      cnt++;
    }
  }
  BipartiteMatching b(cnt);

  for (int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++){
      int from = id[i][j];
      if (from == -1) continue;
      for(int k = 0; k < 4; k++){
        int ny = i + dy[k];
        int nx = j + dx[k];
        if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        int to = id[ny][nx];
        if(to == -1) continue;
        b.add_edge(from, id[ny][nx]);
      }
    }
  }

  int res = b.bipartite_matching();
  // b.output();
  // cout << res << endl;
  cout << cnt - res << endl;
}
