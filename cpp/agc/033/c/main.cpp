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

struct Node {
  vector<int> to;
  bool visited = false;
};

int long_node_index = -1;
int long_d = -1;

void dfs(vector<Node> v, int now, int d){
  d++;
  if(v[now].visited){
    if(d >= long_d){
      long_d = d;
      long_node_index = now;
    }
    return;
  }
  v[now].visited = true;

  for (int i = 0; i < int(v[now].to.size()); i++) {
    if(!v[i+1].visited){
      dfs(v, v[now].to[i], d+1);
    }
  }
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<p> edge(n);
  vector<Node> v(n);

  for (int i = 0; i < n; i++) {
    cin >> edge[i].first >> edge[i].second;
    edge[i].first--;
    edge[i].second--;
    v[edge[i].first].to.push_back(edge[i].second);
    v[edge[i].second].to.push_back(edge[i].first);
  }

}
