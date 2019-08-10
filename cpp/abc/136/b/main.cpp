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
typedef pair<int, int> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if(i >= 1 && i <= 9) res++;
    else if(i >= 100 && i <= 999) res++;
    else if(i >= 10000 && i <= 99999) res++;
  }

  cout << res << endl;
}
