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
  vector<int> v(5);
  for (int i = 0; i < 5; i++) {
    cin >> v[i];
    // ll tmp = v[i];
    // if(tmp % 10 != 0){
    //   tmp = (tmp / 10 + 1) * 10;
    // }
    // res += tmp;
  }
  ll res = INT_MAX;
  for (int i = 0; i < 5; i++) {
    ll tmp = 0;
    for (int j = 0; j < 5; j++) {
      if(j == i) continue;
      if(v[j] % 10 != 0)tmp += (v[j] / 10 + 1) * 10;
      else tmp += v[j];
    }
    tmp += v[i];
    // cout << tmp << endl;
    res = min(res, tmp);
  }

  cout << res << endl;

}
