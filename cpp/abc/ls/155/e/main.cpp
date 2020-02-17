#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  ll res = 0;
  bool flag = false;
  for (int i = int(s.size())-1; i >= 0; i--) {
    int num = s[i] - '0';
    if(flag) num++;
    flag = false;
    if(num >= 6 || (num == 5 && i >= 1 && s[i-1] - '0' >= 4)) {
      res += 10-num;
      flag = true;
    }else{
      res += num;
    }
    // cout << res << endl;
  }

  if(flag) res++;
  cout << res << endl;
}
