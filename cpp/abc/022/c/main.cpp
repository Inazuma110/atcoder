#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> cost(n, vector<int>(n, INT_MAX/2));
  vector<vector<p>> tos(n);
  rep(i, m){
    int from, to, c;
    cin >> from >> to >> c;
    from--; to--;
    cost[from][to] = c;
    cost[to][from] = c;
    tos[from].push_back({c, to});
    tos[to].push_back({c, from});
  }

  rep(i, n) rep(j, n){
    if(i == j){
      cost[i][j] = 0;
    }
  }
  set<p> s;
  rep(i, n-1) rep(j, n){
    if(j <= i) continue;
    s.insert({i, j});
  }

  int res = INT_MAX;
  vector<vector<int>> tmp = cost;
  rep(i, n) {
    tmp[i][0] = INT_MAX/2;
    tmp[0][i] = INT_MAX/2;
  }

  rep(i, n) rep(j, n) rep(k, n){
    tmp[j][k] = min(tmp[j][k], tmp[j][i] + tmp[i][k]);
  }

  for(auto pattern : s){
    int n1 = pattern.first, n2 = pattern.second;
    if(cost[0][n1] == INT_MAX/2 || cost[0][n2] == INT_MAX/2) continue;

    res = min(res, tmp[n1][n2] + cost[n1][0] + cost[n2][0]);
  }


  if(res >= INT_MAX/2) cout << -1 << endl;
  else cout << res << endl;
}
