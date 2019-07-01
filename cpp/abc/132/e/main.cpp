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

int dist[1000500][3];


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 1000500; i++) {
    for (int j = 0; j < 3; j++) {
      dist[i][j] = INT_MAX;
    }
  }
  int n, m;
  cin >> n >> m;
  vector<vector<int>> to(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
  }
  int s, t;
  cin >> s >> t;
  s--; t--;
  queue<p> q;
  // 位置、3の余り
  q.push({s, 0});
  dist[s][0] = 0;
  while(!q.empty()) {
    int v = q.front().first;
    int l = q.front().second;
    q.pop();
    for(auto a : to[v]){
      int nl = (l+1)%3;
      if(dist[a][nl] != INT_MAX) continue;
      dist[a][nl] = dist[v][l]+1;
      q.push({a, nl});
    }
  }

  int res = dist[t][0];
  if(res == INT_MAX) res = -1;
  else res /= 3;
  cout << res << endl;


}
