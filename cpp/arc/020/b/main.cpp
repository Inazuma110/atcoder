#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

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

ll res = INT_MAX;
int n, c;
vector<int> v;

void dfs(int i, ll cost, vector<int> colors){
  if(i == n) {
    chmin(res, cost);
    return;
  }
  for (int j = 1; j <= 10; ++j) {
    colors[i] = j;
    int c1 = colors[0];
    int c2 = colors[1];
    bool flag = true;
    rep(k, i+1){
      if(k % 2 == 0 && colors[k] != c1 && colors[k] != 0) {
        flag = false;
        break;
      }
      if(k % 2 == 1 && colors[k] != c2 && colors[k] != 0){
        flag = false;
        break;
      }
      if(k >= 1 && colors[k] == colors[k-1]){
        flag = false;
        break;
      }
    }
    if(!flag) continue;
    (v[i] == j) ? dfs(i+1, cost, colors) : dfs(i+1, cost+c, colors);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> c;
  v = vector<int> (n);
  rep(i, n) cin >> v[i];
  dfs(0, 0, vector<int> (n));
  cout << res << endl;
}
