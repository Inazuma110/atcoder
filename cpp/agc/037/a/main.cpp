#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = int(s.size());
  int res = 1;
  string before ="";
  before += s[0];
  string next = "";
  for (int i = 1; i < n; i++) {
    next += s[i];
    // cout << before <<endl;
    // cout << next << endl;
    if(before != next){
      res++;
      before = next;
      next = "";
    }
    // cout << "==" << endl;
  }


  cout << res << endl;
}
