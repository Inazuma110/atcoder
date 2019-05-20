#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;

vector<vector<int>> to, cost;
int n;
vector<int> ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  to = vector<vector<int>> (n);
  cost = vector<vector<int>> (n);
  ans = vector<int>(n, -1);
  queue<int> q;
  for (int i = 0; i < n-1; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    to[a].push_back(b);
    cost[a].push_back(w);
    to[b].push_back(a);
    cost[b].push_back(w);
  }
  ans[0] = 0;
  q.push(0);

  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < int(to[v].size()); i++) {
      int u = to[v][i];
      int w = cost[v][i];
      if(ans[u] != -1) continue;
      ans[u] = (ans[v] + w) % 2;
      q.push(u);
    }
  }

  for(auto a : ans) cout << a << endl;

}
