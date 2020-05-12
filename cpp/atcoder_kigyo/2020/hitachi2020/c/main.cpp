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
  int n;
  cin >> n;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n-1){
    int from, to;
    cin >> from >> to;
    from--; to--;
    tree[from].push_back(to);
    tree[to].push_back(from);
  }

  set<int> s1, s2;
  queue<p> q;
  vector<bool> visited(n, false);
  bool iss1 = false;
  q.push({0, iss1});
  // visited[0] = true;
  // for(auto a : tree[0]){
  //   q.push(a);
  // }
  s1.insert(0);
  while(!q.empty()){
    int now = q.front().first;
    iss1 = q.front().second;
    q.pop();
    visited[now] = true;
    for(auto a : tree[now]){
      if(visited[a]) continue;
      q.push({a, !iss1});
      if(iss1) s1.insert(a);
      else s2.insert(a);
    }
  }

  if(s1.size() < s2.size()){
    swap(s1, s2);
  }

  map<int, int> res;
  vector<bool> used(n+1, false);
  if(int(s2.size()) <= n/3){
    int tmp = 3;
    for(auto a : s2){
      res[a] = tmp;
      used[tmp] = true;
      tmp += 3;
    }
    tmp = 1;
    for(auto a : s1){
      res[a] = tmp;
      used[tmp] = true;
      tmp++;
      if(tmp < n && used[tmp]) tmp++;
    }
    for(auto a : res){
      cout << a.second << ' ';
    }
    cout << endl;
    return 0;
  }

  int tmp = 1;
  bool flag = false;
  for(auto a : s1){
    if(tmp > n || flag){
      flag = true;
      if(tmp % 3 != 0) tmp = 3;
      if(tmp > n){
        cout << -1 << endl;
        return 0;
      }
      res[a] = tmp;
      used[tmp] = true;
      tmp += 3;
    }else{
      res[a] = tmp;
      used[tmp] = true;
      tmp += 3;
    }
  }

  // print(res);
  tmp = 2;
  for(auto a : s2){
    res[a] = tmp;
    used[tmp] = true;
    for (; tmp <= n; tmp++) {
      if(!used[tmp]) break;
    }
  }

  for(int i = 0; i < n-1; i++){
    cout << res[i] << ' ';
  }
  cout << res[n-1] << endl;

}
