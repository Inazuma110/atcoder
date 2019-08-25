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
  int m, d;
  cin >> m >> d;
  ll res = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= d; j++) {
      if((j / 10) >= 2 && (j % 10) >= 2){
        if((j % 10) * (j / 10) == i){
          res++;
        }
      }
    }
  }
  cout << res << endl;
}
