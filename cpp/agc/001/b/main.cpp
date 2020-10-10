#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ll n, x;
  cin >> n >> x;
  // ll res = 3 * x * ((n-x) / x);
  n -= x;
  ll res = 0;
  while(x != 0){
    ll tmp = x;
    ll num = n / x;
    res += 3 * x * num;
    if(x == 0) break;
    x = n % x;
    n = tmp;
  }
  cout << res << endl;
}
