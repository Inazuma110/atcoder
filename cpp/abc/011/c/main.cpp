#include <bits/stdc++.h>
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
vector<int> v(3);
vector<int> dp(310, INT_MAX/2);

void dfs(int count){
  for (int i = count; i >= 0; i--) {
    if(v[0] == i || v[1] == i || v[2] == i) continue;

    for (int j = 1; j <= 3; j++) {
      if(i - j >= 0) dp[i-j] = min(dp[i]+1, dp[i-j]);
    }
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  rep(i, 3){
    cin >> v[i];
  }
  rep(i, 3){
    if(v[i] == n){
      cout << "NO" << endl;
      return 0;
    }
  }

  dp[n] = 0;
  dfs(n);

  if(dp[0] <= 100) cout << "YES" << endl;
  else cout << "NO" << endl;
}
