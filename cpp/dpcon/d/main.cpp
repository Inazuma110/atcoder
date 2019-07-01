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

ll dp[300][100100];


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<int> val(n), weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i] >> val[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 100100; j++) {
      if(j >= weight[i-1]) {
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + val[i-1]);
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout << dp[n][w] << endl;

}
