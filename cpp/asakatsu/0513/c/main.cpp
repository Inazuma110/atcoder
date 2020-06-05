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

vector<vector<int>> tree;
vector<bool> visited;
int n;
int dfs(int from){
  if(tree[from].size() == 1 && visited[tree[from][0]]){
    return 1;
  }
  visited[from] = true;
  vector<int> tmp;
  for(auto to : tree[from]){
    if(visited[to]) continue;
    tmp.push_back(dfs(to));
  }
  // print(tmp);
  return *min_element(ALL(tmp)) + *max_element(ALL(tmp)) + 1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  tree = vector<vector<int>> (n);
  rep(i, n-1){
    int to;
    cin >> to;
    to--;
    tree[i+1].push_back(to);
    tree[to].push_back(i+1);
  }
  visited = vector<bool> (n);
  visited[0] = true;
  int res = dfs(0);
  cout << res << endl;
}
