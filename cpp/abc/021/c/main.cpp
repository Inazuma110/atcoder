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
  int n, a, b;
  cin >> n >> a >> b;
  a--;b--;
  int m;
  cin >> m;
  vector<vector<int>> v(n, vector<int>(n, INT_MAX / 2));
  rep(i, n) v[i][i] = 0;
  rep(i, m) {
    int from, to;
    cin >> from >> to;
    from--; to--;
    v[from][to] = 1;
    v[to][from] = 1;
  }

  rep(i, n) rep(j, n) rep(k, n){
    v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
  }

  vector<int> d(n, INT_MAX), count(n);
  queue<int> q;
  q.push(a);
  d[a] = 0;
  count[a] = 1;

  while(!q.empty()) {
    int now = q.front();
    q.pop();
    if(now == b) break;
    for (int i = 0; i < n; i++) {
      if(v[now][i] == 1){
        if(d[i] == INT_MAX){
          d[i] = d[now] + 1;
          count[i] += count[now];
          count[i] %= MOD;
          q.push(i);
        }else if(d[i] == d[now] + 1){
          count[i] += count[now];
          count[i] %= MOD;
        }
      }
    }
  }
  // print(d);
  // print(count);
  cout << count[b] << endl;
}
