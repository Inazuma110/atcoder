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
  string s;
  cin >> s;
  int res = 0;
  int count = 0;
  for (int i = 0; i < int(s.size()); i++) {
    if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
      count++;
    }else{
      count = 0;
    }
    res = max(count, res);
  }
  cout << res << endl;
}
