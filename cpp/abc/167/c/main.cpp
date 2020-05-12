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

int n, m, x;
vector<vector<int>> v;
vector<int> mon;
int res = INT_MAX;
void dfs(int step, vector<int> state){
  if(step == n){
    vector<int> nows(m);
    int nm = 0;
    rep(i, n){
      if(state[i] == 0) continue;
      nm += mon[i];
      rep(j, m){
        nows[j] += v[i][j];
      }
    }
    bool flag = true;
    rep(i, m){
      if(nows[i] < x) flag = false;
    }
    if(flag) chmin(res, nm);
    return;
  }
  dfs(step+1, state);
  state[step] = 1;
  dfs(step+1, state);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> x;
  v = vector<vector<int>> (n, vector<int> (m));
  mon = vector<int> (n);
  rep(i, n){
    cin >> mon[i];
    rep(j, m) cin >> v[i][j];
    // sort(RALL(v[i]));
  }

  dfs(0, vector<int> (n));
  if(res == INT_MAX) cout << -1 << endl;
  else cout << res << endl;
}
