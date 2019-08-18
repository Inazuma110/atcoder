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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];

  int res = -INT_MAX;
  for (int i = 0; i < n; i++) {
    int max_score = -INT_MAX;
    int max_i = -1;
    int max_taka = 0;
    for (int j = 0; j < i; j++) {
      if(i == j) continue;
      int takahashi = 0, aoki = 0;
      for (int k = j; k <= i; k++) {
        if((k-j) % 2 == 0) takahashi += v[k];
        else aoki += v[k];
      }
      if(max_score < aoki){
        max_score = aoki;
        max_i = j;
        max_taka = takahashi;
      }
    }

    for (int j = i+1; j < n; j++) {
      int takahashi = 0, aoki = 0;
      for (int k = i; k <= j; k++) {
        if((k-i) % 2 == 0) takahashi += v[k];
        else aoki += v[k];
      }
      if(max_score < aoki){
        max_score = aoki;
        max_i = j;
        max_taka = takahashi;
      }
    }
    res = max(res, max_taka);
    // cout << i << " : " << max_i << endl;
    // cout << res << endl;
  }
  cout << res << endl;
}
