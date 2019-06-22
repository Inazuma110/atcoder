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
  int maxv  = (n-1)*(n-2)/2;
  if(maxv < k){
    cout << -1 << endl;
    return 0;
  }
  vector<p> res;
  for (int i = 1; i <= n-1; i++) {
    res.push_back({i, n});
  }

  int add = maxv - k;
  for (int i = 2; i <= n-1 ; i++) {
    for (int j = 1; j < i; j++) {
      if(add == 0) break;
      res.push_back({i, j});
      add--;
    }
  }

  cout << res.size() << endl;
  for(auto a : res){
    cout << a.first << ' ' << a.second << endl;
  }


}
