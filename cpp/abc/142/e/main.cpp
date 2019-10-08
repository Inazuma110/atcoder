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

typedef long long ll;
typedef pair<ll, ll> p;

int n, m;
ll res = LLONG_MAX;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vector<p> key;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    int s = 0;
    rep(j, b){
      int c;
      cin >> c;
      c--;
      s |= (1<<c);
    }
    key.push_back({s, a});
  }
  vector<ll> dp(1<<n, INT_MAX);
  dp[0] = 0;

  rep(s, 1<<n){
    rep(i, m){
      int t = s | key[i].first;
      ll cost = dp[s] + key[i].second;
      dp[t] = min(dp[t], cost);
    }
  }

  if(dp[(1<<n)-1] == INT_MAX) cout << -1 << endl;
  else cout << dp.back() << endl;
}
