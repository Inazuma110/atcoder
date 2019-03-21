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

vector<int> dp(100100, 0);
vector<bool> flag(100100, false);

int dfs(int x){
  if(flag[x]) return dp[x];
  flag[x] = true;

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<p> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
  }



}
