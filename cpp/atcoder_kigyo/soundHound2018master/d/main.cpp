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

struct Graph {
  vector<vector<p>> yen;
  vector<vector<p>> snuke;
  vector<bool> visited1;
  vector<bool> visited2;
  vector<ll> min_cost1;
  vector<ll> min_cost2;
  int node_num, edge_num;

  Graph(int nn, int en) : node_num(nn), edge_num(en){
    min_cost1 = vector<ll> (node_num, INT_MAX);
    min_cost2 = vector<ll> (node_num, INT_MAX);
    yen = vector<vector<p>> (node_num, vector<p>());
    snuke = vector<vector<p>> (node_num, vector<p>());
  }

  void dijkstra1(int start){
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, start});
    min_cost1[start] = 0;

    while(!pq.empty()) {
      int now_cost = pq.top().first;
      int now = pq.top().second;
      pq.pop();
      if(min_cost1[now] < now_cost) continue;

      for(auto e : yen[now]){
        if(min_cost1[e.first] > now_cost + e.second){
          min_cost1[e.first] = now_cost + e.second;
          pq.push({min_cost1[e.first], e.first});
        }
      }
    }
  }


  void dijkstra2(int start){
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, start});
    min_cost2[start] = 0;

    while(!pq.empty()) {
      int now_cost = pq.top().first;
      int now = pq.top().second;
      pq.pop();
      if(min_cost2[now] < now_cost) continue;

      for(auto e : snuke[now]){
        if(min_cost2[e.first] > now_cost + e.second){
          min_cost2[e.first] = now_cost + e.second;
          pq.push({min_cost2[e.first], e.first});
        }
      }
    }
  }

  void init(){
    visited1 = vector<bool> (node_num, false);
    min_cost1 = vector<ll> (node_num, INT_MAX);
  }
};



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--;t--;
  Graph g(n, m);
  for (int i = 0; i < m; i++) {
    int from, to, yen, snuke;
    cin >> from >> to >> yen >> snuke;
    from--; to--;
    g.yen[from].push_back({to, yen});
    g.yen[to].push_back({from, yen});
    g.snuke[to].push_back({from, snuke});
    g.snuke[from].push_back({to, snuke});
  }

  g.dijkstra1(s);
  g.dijkstra2(t);

  vector<ll> res(n, LLONG_MAX);
  ll now = LLONG_MAX;
  ll money = pow(10, 15);

  for (int i = n-1; i >= 0; i--) {
    now = min(now, g.min_cost1[i]+g.min_cost2[i]);
    res[i] = money - now;
  }

  for (int i = 0; i < n; i++) {
    cout << res[i] << endl;
  }
}
