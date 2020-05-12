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
vector<pair<int, int> > G[400000];

class LCA {
public:
    int V, logV;
    vector<int> depth, len;
    vector<vector<int> > parent;

    LCA(int V) {
        this->V = V;
        logV = 0;
        while (V > (1LL<<logV)) logV++;
        this->depth = vector<int>(V);
        this->len = vector<int>(V);
        this->parent = vector<vector<int> >(logV, vector<int>(V));
    }

    void init(int v, int par, int d, int l) {
        depth[v] = d;
        parent[0][v] = par;
        len[v] = l;
        for (int i = 0; i < (int)G[v].size(); i++) {
            int w = G[v][i].first;
            int lc = G[v][i].second;
            if (w == par) continue;
            init(w, v, d+1, lc + l);
        }
    }

    void build() {
        for (int k = 0; k + 1 < logV; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }

    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < logV; k++) {
            if ((depth[v] - depth[u]) >> k & 1)
                v = parent[k][v];
        }
        if (u == v) return u;

        for (int k = logV-1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  rep(i, n-1){
    int from, to;
    cin >> from >> to;
    from--; to--;
    G[from].push_back({to, 1});
    G[to].push_back({from, 1});
  }
  LCA lca(n);
  lca.init(0, -1, 0, 0);
  lca.build();

  map<int, int> res;
  vector<vector<int>> three(n, vector<int>());
  vector<p> tmps(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int z = lca.query(i, j);
      int ret = lca.len[i] + lca.len[j] - 2 * lca.len[z];
      if(ret == 3) three[i].push_back(j);
    }
    tmps[i] = {int(three[i].size()), i};
  }
  sort(RALL(tmps));

  int tmp = 3;
  for (int i = 0; i < n; i++){
    if(tmp > n) break;
    int t = tmps[i].second;
    res[t] = tmp;
    tmp *= 3;
  }
  tmp = 1;
  vector<bool> used(n+1, false);

  for (int i = 0; i < n; i++) {
    if(res[i] % 3 == 0) continue;
    for(auto a : three[i]){
      if(res[a] % 3 == 0) continue;
      res[i] = tmp;
      tmp++;
      res[a] = tmp;
      tmp += 2;
    }
  }

  tmp = 0;

  for (int i = 0; i < n; i++) {
    if(res[i] != 0) continue;
    tmp++;
    if(tmp % 3 == 0) tmp++;
    res[i] = tmp;
  }
  // print(res);
  // print(three);

  for (int i = 0; i < n; i++) {
    for(auto a : three[i]){
      if((res[i] + res[a]) % 3 != 0 && (res[i]*res[a]) % 3 != 0){
        cout << -1 << endl;
        return 0;
      }
    }
  }

  for(auto a : res){
    cout << a.second << ' ';
  }
  cout << endl;

}
