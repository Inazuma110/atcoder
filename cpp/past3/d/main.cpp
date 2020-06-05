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
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> graph(n);
  rep(i, m){
    int from, to;
    cin >> from >> to;
    from--; to--;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  vector<int> col(n);
  rep(i, n) cin >> col[i];

  for (int i = 0; i < q; ++i) {
    int t, x;
    cin >> t >> x;
    x--;
    cout << col[x] << endl;
    if(t == 1){
      for(auto to : graph[x]){
        col[to] = col[x];
      }
    }else{
      int y;
      cin >> y;
      col[x] = y;
    }
  }
}
