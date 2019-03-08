#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;
int n;

// void init(){
//   vector<int> tmp(100010, INT_MAX);
//   tmp[0] = 1;
//   // tmp[1] = 1;
//   dp = tmp;
// }

int main(){
  cin >> n;
  vector<int> dp(100100, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i < 100100; i++) {
    int power = 1;
    while(power <= i) {
      dp[i] = min(dp[i], dp[i-power]+1);
      power *= 6;
    }

    power = 1;
    while(power <= i) {
      dp[i] = min(dp[i], dp[i-power]+1);
      power *= 9;
    }
  }

  cout << dp[n] << endl;
}
