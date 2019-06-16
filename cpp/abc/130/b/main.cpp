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
  ll sum = 0;
  ll res = 1;
  for (int i = 0; i < n; i++) {
    sum += v[i];
    if(sum > x){
      cout << res << endl;
      return 0;
    }
    res++;
  }
  cout << n+1 << endl;
}
