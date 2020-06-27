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

bool check(string s, string t){
  int m = int(s.size());
  int count = 0;
  for (int i = 0; i < m; ++i) {
    if(s[i] != t[i]) count++;
  }
  return count == 1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string first, last;
  cin >> first >> last;
  // int m = int(first.size());
  int n;
  cin >> n;
  vector<string> v(n);
  rep(i, n) cin >> v[i];
  vector<vector<int>> graph(n+2);
  if(check(first, last)) graph[0].push_back(n+1);

  for (int i = 0; i < n; ++i) {
    if(check(first, v[i])){
      graph[0].push_back(i+1);
      graph[i+1].push_back(0);
      // graph[i+1].push_back({0, 1});
    }
    if(check(last, v[i])){
      // graph[n+1].push_back({i+1, 1});
      graph[i+1].push_back(n+1);
      graph[n+1].push_back(i+1);
    }

    for (int j = i+1; j < n; ++j) {
      if(i == j) continue;
      if(v[j] == first || v[j] == last) continue;
      if(check(v[i], v[j])){
        graph[i+1].push_back(j+1);
        graph[j+1].push_back(i+1);
      }
    }
  }
  if(first == last){
    cout << 0 << endl;
    cout << first << endl;
    cout << last << endl;
    exit(0);
  }

  queue<pair<p, vector<int>>> q;
  q.push({{0, 0}, vector<int>()});
  vector<bool> visited(n+2);
  visited[0] = true;
  vector<int> path;
  vector<int> min_path;
  int minv = INT_MAX;
  while (!q.empty()) {
    int from = q.front().first.first;
    int d = q.front().first.second;
    vector<int> path = q.front().second;
    q.pop();
    path.push_back(from);
    // visited[from] = true;
    if(from == n+1){
      if(minv > d){
        minv = d;
        min_path = path;
      }
    }
    for(auto to : graph[from]){
      if(visited[to]) continue;
      visited[to] = true;
      q.push({{to, d+1}, path});
    }
  }

  // print(graph);
  // print(path);
  // print(min_path);

  if(minv == INT_MAX) cout << -1 << endl;
  else{
    cout << minv-1 << endl;
    for(auto p : min_path){
      if(p == 0) cout << first << endl;
      else if(p == n+1) cout << last << endl;
      else cout << v[p-1] << endl;
    }
  }
}
