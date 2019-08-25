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

ll n, h;
int dp[1000000][2];
int money[1000000];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> h;
  ll a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;

  ll money = LLONG_MAX;

  for (int i = 0; i <= n; i++) {
    int j = double((n - i) * e - h - b * i) / double(d + e);
    j = max(j, 0);
    for (; j + i <= n; j++) {
    if(b * i + d * j + h > e * (n - (i + j))){
      ll tmp = i * a + j * c;
      money = min(money, tmp);
      break;
    }
    }
  }

  cout << money << endl;
}
