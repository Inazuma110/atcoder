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
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  ll res = 0;
  if(v[0] > x){
    res += v[0] - x;
    v[0] = x;
    res += v[1];
    v[1] = 0;
  }

  for (int i = 1; i < n; i++) {
    if(v[i-1] + v[i] > x){
      res += v[i] - (x - v[i-1]);
      v[i] = x - v[i-1];
    }
  }

  cout << res << endl;
}
