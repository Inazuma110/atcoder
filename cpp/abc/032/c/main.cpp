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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  ll res = 0;
  ll count = 1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if(v[i] == 0){
      cout << n << endl;
      return 0;
    }
  }

  ll before = 0;
  ll now = 0;

  for (int i = 0; i < n; i++) {
    count *= v[i];
    now++;
    while(count > k && before <= i){
      count /= v[before];
      before++;
      now--;
    }
    res = max(res, now);
  }

  cout << res << endl;
}
