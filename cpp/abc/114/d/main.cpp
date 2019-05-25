#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

int dp[110];

void init(){
  for (int i = 0; i < 110; i++) {
    dp[i] = 0;
  }
}

int main(){
  ll n;
  cin >> n;
  ll res = 0;
  init();
  for (int i = 1; i <= n; i++) {
    ll count = dp[i-1];
    for (int j = 1; j <= i; j++) {
      if(i % j == 0){
        count++;
      }
    }
    dp[i] = count;
    if(dp[i] == 75){
      res++;
    }
  }
  print(dp);

  // cout << res << endl;

}
