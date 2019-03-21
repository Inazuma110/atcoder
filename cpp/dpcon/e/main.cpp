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

ll dp[200][500100];

void init(){
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 500100; j++) {
      dp[i][j] = INT_MAX;
    }
  }
  dp[0][0] = 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<p> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  init();

  for (int i = 1; i <= n; i++) {
    ll weight = v[i-1].first;
    ll val = v[i-1].second;
    for (int j = 0; j < 500100; j++) {
      if(j - val >= 0){
        dp[i][j] = min(dp[i-1][j], dp[i-1][j-val] + weight);
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  int ans = 500000;
  while(dp[n][ans] > w) ans--;

  cout << ans << endl;


}
