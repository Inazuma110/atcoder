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
  reverse(ALL(s));
  int now = 0;
  while(now < int(s.size())) {
    if(s.substr(now, 5) == "maerd"){
      now += 5;
    }else if(s.substr(now, 7) == "remaerd"){
      now += 7;
    }else if(s.substr(now, 5) == "esare"){
      now += 5;
    }else if(s.substr(now, 6) == "resare"){
      now += 6;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}
