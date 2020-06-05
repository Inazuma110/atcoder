#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <queue>

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
  vector<vector<int>> tree(n);
  rep(i, n-1){
    int from, to;
    cin >> from >> to;
    from--;to--;
    tree[from].push_back(to);
    tree[to].push_back(from);
  }

  priority_queue<p> pq;
  pq.push({0, 0});
  vector<int> visited(n, false);

  vector<int> res;
  while(!pq.empty()){
    int from = -pq.top().first;
    int d = pq.top().second;
    pq.pop();
    visited[from] = true;
    res.push_back(from);

    for(auto to : tree[from]){
      if(visited[to]) continue;
      pq.push({-to, d+1});
    }
  }

  rep(i, n-1) cout << res[i]+1 << ' ';
  cout << res[n-1]+1 << endl;
}
