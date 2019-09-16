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
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    // -2i -j = m - 4n
    // j = 4n - m - 2i
    int j = 4 * n - m - 2 * i;
    int k = n - i - j;
    if(j < 0 || k < 0) continue;
    if(2 * i + 3 * j + 4 * k == m){
      cout << i << ' ' << j << ' ' << k << ' ' << endl;
      return 0;
    }
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
}
