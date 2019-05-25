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
  string s;
  cin >> n >> s;

  int count = 0;

  for (int i = 0; i < n; i++) {
    if(s[i] == '(') count++;
    if(count > 0 && s[i] == ')') count--;
  }
  if(count > 0){
    for (int i = 0; i < count; i++) {
      s += ')';
    }
  }
  n = int(s.size());
  count = 0;

  for (int i = n-1; i >= 0; i--) {
    if(s[i] == ')') count++;
    if(count > 0 && s[i] == '(') count--;
  }
  if(count > 0){
    for (int i = 0; i < count; i++) {
      string tmp = s;
      s = '(' + tmp;
    }
  }
  cout << s << endl;


}
