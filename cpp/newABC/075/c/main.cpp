#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;


int n, m;
bool graph[60][60];
bool visited[60];

void init(){
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
}

void dfs(int x){
  if(visited[x]) return;
  visited[x] = true;
  for (int i = 0; i < n; i++) {
    if(graph[x][i]){
      dfs(i);
    }
  }
}


int main(){
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    graph[a[i]][b[i]] = true;
    graph[b[i]][a[i]] = true;
  }
  int res = 0;

  for (int i = 0; i < m; i++) {
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
    init();

    dfs(0);

    bool connect = true;
    for (int i = 0; i < n; i++) {
      if(!visited[i]) connect = false;
    }
    if(!connect) res++;
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;

  }


  cout << res << endl;

}
