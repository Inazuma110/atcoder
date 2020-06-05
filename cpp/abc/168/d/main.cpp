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

struct edge {
    int to, cost;
};
typedef vector<vector<edge> > AdjList;
AdjList graph;

typedef pair<int, int> P;

const int INF = 10000000;

vector<int> dist;
vector<int> prever;

void dijkstra(int n, int s){
    dist = vector<int>(n,INF);
    prever = vector<int>(n,-1);
    dist[s] = 0;

    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(dist[v] < p.first){
            continue;
        }
        for(int i=0;i<graph[v].size();i++){
            edge e = graph[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                prever[e.to] = v;
                que.push(P(dist[e.to],e.to));
            }
        }
    }
}

vector<int> get_path(int t){ //頂点tへの最短路
    vector<int> path;
    for(; t != -1;t=prever[t]){
        path.push_back(t);
    }

    reverse(path.begin(), path.end());
    return path;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  // AdjList g(n);
  graph = AdjList(n);
  rep(i, m){
    int from, to;
    cin >> from >> to;
    from--; to--;
    graph[from].push_back({to, 1});
    graph[to].push_back({from, 1});
  }

  dijkstra(n, 0);

  for(auto de : dist){
    if(de == INF){
      cout << "No" << endl;
      return 0;
    }
  }

  vector<int> res(n);
  queue<int> q;
  vector<bool> visited(n);
  visited[0] = true;
  q.push(0);

  while(!q.empty()){
    int from = q.front();
    q.pop();

    for(auto a : graph[from]){
      int to = a.to;
      if(visited[to]) continue;
      visited[to] = true;
      res[to] = from;
      q.push(to);
    }
  }

  cout << "Yes" << endl;
  for (int i = 1; i < n; ++i) {
    cout << res[i] + 1 << endl;
  }


}
