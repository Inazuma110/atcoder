#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;

int dp[100100];
int n, m;
vector<int> v;

void init(){
  for (int i = 0; i < 100100; i++) {
    dp[i] = 0;
  }
  dp[0] = 1;
  dp[1] = 1;
}

ll res = 0;
void solve(){
  for (int i = 2; i <= n; i++) {
    if(dp[i] == -1) continue;
    if(dp[i-1] == -1 && dp[i-2] == -1) dp[i] = 0;
    else if(dp[i-1] != -1 && dp[i-2] != -1){
      dp[i] = dp[i-1] + dp[i-2];
    }else if(dp[i-1] == -1){
      dp[i] = dp[i-2];
    }else if(dp[i-2] == -1){
      dp[i] = dp[i-1];
    }
    dp[i] %= MOD;
  }
  res = dp[n];
  cout << res << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  v = vector<int> (m);
  init();
  for (int i = 0; i < m; i++) {
    cin >> v[i];
  }
  for(auto a : v){
    dp[a] = -1;
  }
  solve();
}
