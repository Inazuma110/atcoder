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

int b[2][3], c[3][2];
int who[3][3];

int dfs(int n){
  if(n == 9){
    int ans = 0;
    rep(i, 2) rep(j, 3){
      if(who[i][j] == who[i+1][j]) ans += b[i][j];
    }
    rep(i, 3) rep(j, 2){
      if(who[i][j] == who[i][j+1]) ans += c[i][j];
    }
    return ans;
  }

  int ans = -1;
  rep(i, 3) rep(j, 3){
    if(who[i][j] != 0) continue;
    who[i][j] = n % 2 ? 1 : -1;
    int tmp = dfs(n+1);
    if(ans == -1) ans = tmp;
    else if(n % 2 != 0) ans = min(ans, tmp);
    else ans = max(ans, tmp);
    who[i][j] = 0;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int sum = 0;
  rep(i, 2) rep(j, 3){
    cin >> b[i][j];
    sum += b[i][j];
  }
  rep(i, 3) rep(j, 2){
    cin >> c[i][j];
    sum += c[i][j];
  }
  int a = dfs(0);
  cout << a << endl;
  cout << sum - a << endl;
}
