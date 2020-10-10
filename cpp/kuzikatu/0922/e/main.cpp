#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
// using namespace atcoder;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
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
  vector<p> v(n);
  vector<ll> scores(n);
  vector<vector<int>> g(n);
  rep(i, n-1){
    cin >> v[i].first >> v[i].second;
    v[i].first--, v[i].second--;
    g[v[i].first].push_back(v[i].second);
    g[v[i].second].push_back(v[i].first);

  }
  rep(i, n) cin >> scores[i];
  sort(RALL(scores));

  stack<int> st;
  st.push(0);

  vector<bool> visited(n);
  visited[0] = true;
  vector<int> ans(n);
  int cnt = 0;
  while(!st.empty()){
    int from = st.top();
    st.pop();
    visited[from] = 1;
    ans[from] = scores[cnt];
    cnt++;

    for (auto to : g[from]) {
      if(visited[to]) continue;
      st.push(to);
    }
  }

  ll res = 0;
  rep(i, n-1){
    res += min(ans[v[i].first], ans[v[i].second]);
  }

  cout << res << endl;
  rep(i, n-1) cout << ans[i] << ' ';
  cout << ans[n-1] << endl;

}
