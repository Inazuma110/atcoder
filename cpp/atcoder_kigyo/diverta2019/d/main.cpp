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
  ll n;
  cin >> n;
  ll res = 0;

  ll before = -1;
  for (int i = 1; i <= n; i++){
    if(n % i == n / i) {
      res += i;
      before = n / i;
    }
    else if(before == n / i){
      res += i * (n / i) + n % i - 1;
      before = n / i;
      i = i * (n / i) + n % i - 1;
    }
  }

  cout << res << endl;
}
