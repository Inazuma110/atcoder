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
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;

  s[a-1] = 'a';
  s[b-1] = 'b';

  bool flag = false;
  for (int i = b-1; i < d; i++) {
    if(((s[i-1] == '#' && s[i] == '#') || (s[i] == '#' && s[i+1] == '#'))){
      cout << "No" << endl;
      return 0;
    }
    if((i == 0 || s[i-1] == '.') && s[i] == '.' && (i == n-1 || s[i+1] == '.')){
      flag = true;
      s[i] = '#';
      s[b-1] = '.';
      b = i;
      break;
    }
  }

  if(!flag) s[b-1] = '#';
  for (int i = a; i < c-1; i++) {
    if(i == n-1) break;
    if((s[i] == '#' || s[i] == 'b') && ((s[i+1] == '#' || s[i+1] == 'b'))){
      cout << "No" << endl;
      return 0;
    }
  }
  s[c-1] = '#';
  s[a-1] = '.';

  for (int i = b; i < d-1; i++) {
    if(i == n-1) break;
    if(s[i] == '#' && (s[i+1] == '#')){
      cout << "No" << endl;
      return 0;
    }
  }
  s[b-1] = '.';
  s[d-1] = '#';

  cout << "Yes" << endl;
}
