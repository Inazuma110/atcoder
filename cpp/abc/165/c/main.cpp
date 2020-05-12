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

int n, m, q;
ll res = 0;
vector<int> a, b, c, d;

void solve(vector<int> state){
  ll tmp = 0;
  for (int i = 0; i < q; ++i) {
    if(state[b[i]-1] - state[a[i]-1] == c[i]) tmp += d[i];
  }
  // print(state);
  // cout << tmp <<endl;
  chmax(res, tmp);
}

void dfs(int step, vector<int> state){
  if(step == n) {
    solve(state);
    return;
  }

  for (int i = 1; i <= m; ++i) {
    if(step >= 1) chmax(i, state[step-1]);
    state[step] = i;
    dfs(step+1, state);
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >>  n >> m >> q;
  a = vector<int> (q);
  b = vector<int> (q);
  c = vector<int> (q);
  d = vector<int> (q);
  rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  dfs(0, vector<int> (n));
  cout << res << endl;
}
