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
  int n, l;
  cin >> n >> l;
  ll res = 0;
  if(l < 0 && l + n > 0){
    for (int i = 0; i < n; i++) {
      res += l + i;
    }
  } else if(l >= 0){
    for (int i = 1; i < n; i++){
      res += l + i;
    }
  }else{
    for (int i = 0; i < n-1; i++){
      res += l + i;
    }
  }

  cout << res << endl;

}
