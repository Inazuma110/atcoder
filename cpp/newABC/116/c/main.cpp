#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

int main(){
  int n;
  int res = 0;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  while(true) {
    bool flag = true;
    int l = 0;
    int r = n;
    for (int i = 0; i < n; i++) {
      if(v[i] > 0 && flag)
      {
        l = i;
        flag = false;
      }
      if(!flag && v[i] == 0 && i > l) {
        r = i;
        break;
      }
    }
    // cout << l << " : " << r << endl;
    for (int i = l; i < r; i++) {
      v[i]--;
    }
    // print(v);
    res++;
    if(flag) break;
  }

  cout << res-1 << endl;

}
