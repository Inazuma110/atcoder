#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

typedef long long ll;
typedef pair<int, int> p;


int main(){
  string s;
  cin >> s;
  int n = int(s.size());
  ll res = 0;
  for (int i = 0; i < n; i++) {
    int now = i + 1;
    if(s[i] == 'U'){
      res += n - now;
      res += 2 * i;
    }else{
      res += 2 * (n - now);
      res += i;
    }
  }

  cout << res << endl;
}
