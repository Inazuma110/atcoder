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
vector<int> a;
vector<int> b;
vector<int> c;
int dp[200000][3];

void init(){
  cin >> n;
  vector<int> va(n);
  vector<int> vb(n);
  vector<int> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> va[i] >> vb[i] >> vc[i];
  }
  a = va;
  b = vb;
  c = vc;
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];
}

void solve(){
  for (int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
    dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
    dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + c[i];
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  solve();
  ll res = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
  cout << res << endl;
}
