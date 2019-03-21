#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;


ll dp[200][200000];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<p> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }

  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 200000; j++) {
      dp[i][j] = 0;
    }
  }
  // i番目までのもので重さj以下価値最大

  for (int i = 1; i <= n; i++) {
    int weight = v[i-1].first;
    int val = v[i-1].second;
    for (int j = 0; j <= w; j++) {
      if(j - weight >= 0)
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + val);
      else
        dp[i][j] = dp[i-1][j];
    }
  }

  cout << dp[n][w] << endl;
}
