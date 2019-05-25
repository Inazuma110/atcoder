#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

typedef long long ll;
typedef pair<int, int> p;

ll dp[100010][4] = {};
string s;
ll n;

void init(){
  n = int(s.size());
  // dp[0][0] = 1;
}

void solve(){
  for (int i = n; i >= 0; i--) {
    for (int j = 3; j >= 0; j--) {
      if(i == n) dp[i][j] = (j == 3 ? 1 : 0);
      else{
        dp[i][j] = dp[i+1][j] * (s[i] == '?' ? 3LL : 1LL);
        if(j < 3 && (s[i] == '?' || s[i] == "ABC"[j])){
          dp[i][j] += dp[i+1][j+1];
        }
        dp[i][j] %= MOD;
      }
    }
  }
}

int main(){
  cin >> s;
  init();
  solve();
  cout << dp[0][0] << endl;
}

