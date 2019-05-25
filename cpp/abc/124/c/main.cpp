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
  string s;
  cin >> s;
  int n = int(s.size());
  int res = INT_MAX;

  int count = 0;
  for (int i = 0; i < n; i++) {
    if(i % 2 == 0){
      if(s[i] == '1') count++;
    }else{
      if(s[i] == '0') count++;
    }
  }
  res = min(res, count);

  count = 0;
  for (int i = 0; i < n; i++) {
    if(i % 2 == 0){
      if(s[i] == '0') count++;
    }else{
      if(s[i] == '1') count++;
    }
  }
  res = min(res, count);

  // for (int i = n-1; i >= 0; i--) {
  //   if(i % 2 == 0){
  //     if(s[i] == '0') count++;
  //   }else{
  //     if(s[i] == '1') count++;
  //   }
  // }
  //
  // for (int i = n-1; i >= 0; i--) {
  //   if(i % 2 == 0){
  //     if(s[i] == '1') count++;
  //   }else{
  //     if(s[i] == '0') count++;
  //   }
  // }
  cout << res << endl;

}
