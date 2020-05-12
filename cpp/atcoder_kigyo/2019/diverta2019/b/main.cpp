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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  ll res = 0;
  for (int i = 0; i <= 3000; i++) {
    for (int j = 0; j <= 3000; j++) {
      if((n - (r*i + g*j) >= 0) && ((n - (r*i+g*j)) % b == 0)){
        // cout << i << ' ' << j << ' ' << (n-(r*i+g*j))%b << endl;
        res++;
      }
    }
  }
  cout << res << endl;
}
