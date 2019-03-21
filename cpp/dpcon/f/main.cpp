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

int dp[5000][5000];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int s_len = int(s.size());
  int t_len = int(t.size());

  for (int i = 1; i <= s_len; i++) {
    for (int j = 1; j <= t_len; j++) {
      if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  int len = dp[s_len][t_len];
  int i = s_len;
  int j = t_len;
  vector<char> ans(len+1);
  while(len >= 0){
    if(s[i] == t[j]){
      // cout << i << endl;
      // cout << j << endl;
      ans[len] = s[i];
      i--;
      j--;
      len--;
    }else if(dp[i][j] == dp[i-1][j]) i--;
    else j--;
  }

  // print(ans);

  for(auto a : ans) cout << a;
  cout << endl;


}
