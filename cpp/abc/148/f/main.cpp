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

typedef long long ll;
typedef pair<ll, ll> p;

struct Graph {
  vector<vector<p>> cost;
  vector<bool> visited;
  vector<int> min_cost;
  int node_num, edge_num;

  Graph(int nn, int en) : node_num(nn), edge_num(en){
    min_cost = vector<int> (node_num, INT_MAX);
    cost = vector<vector<p>> (node_num, vector<p>());
  }


  void dijkstra(int start){
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, start});
    min_cost[start] = 0;

    while(!pq.empty()) {
      int now_cost = pq.top().first;
      int now = pq.top().second;
      pq.pop();
      if(min_cost[now] < now_cost) continue;

      for(auto e : cost[now]){
        if(min_cost[e.first] > now_cost + e.second){
          min_cost[e.first] = now_cost + e.second;
          pq.push({min_cost[e.first], e.first});
        }
      }
    }
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, u, v;
  cin >> n >> u >> v;
  Graph g1(n, n-1);
  Graph g2(n, n-1);
  u--;v--;

  for (int i = 0; i < n-1; i++) {
    int from, to;
    cin >> from >> to;
    from--; to--;
    g1.cost[from].push_back({to, 1});
    g1.cost[to].push_back({from, 1});
    g2.cost[from].push_back({to, 1});
    g2.cost[to].push_back({from, 1});
  }
  g1.dijkstra(u);
  g2.dijkstra(v);

  int res = 0;

  for (int i = 0; i < n; i++) {
    if(g2.min_cost[i] - g1.min_cost[i] == 1){
      res = max(res, g1.min_cost[i]);
    }else if(g2.min_cost[i] - g1.min_cost[i] == 0){
      res = g2.min_cost[i];
      cout << res << endl;
      return 0;
    }
  // cout << res << endl;
  }

  cout << res << endl;
  // print(g1.min_cost);
  // print(g2.min_cost);
}
