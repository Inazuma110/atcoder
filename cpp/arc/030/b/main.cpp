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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> h(n);
  map<int, int> mp;
  rep(i, n){
    cin >> h[i];
    mp[i] = h[i];
  }
  vector<vector<int>> tree(n);
  rep(i, n-1) {
    int from, to;
    cin >> from >> to;
    from--; to--;
    tree[from].push_back(to);
    tree[to].push_back(from);
  }

  vector<bool> visited(n);
  queue<p> q;
  q.push({x-1, 0});
  visited[x-1] = true;
  int res = 0;
  while(!q.empty()){
    int from = q.front().first;
    int d = q.front().second;
    q.pop();
    visited[from] = true;
    if(tree[from].size() == 1 && visited[tree[from][0]]){
      cout << from << ' ' << d << endl;
      if(mp[from]) res += d * 2;
    }
    for(auto to : tree[from]){
      if(visited[to]) continue;
      if(tree[from].size() >= 3) q.push({to, 1});
      else q.push({to, d+1});
    }
  }
  cout << res << endl;
}

