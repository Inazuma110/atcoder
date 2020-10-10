#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
// using namespace atcoder;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
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
  int n = (int)s.size();
  int first = 0, end = n-1;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    // cout << first << ' ' << end << endl;
    if(first >= end) break;
    if(s[first] == s[end]){
      first++;
      end--;
      continue;
    }
    else{
      res++;
      if(s[first] == 'x') first++;
      else if(s[end] == 'x')end--;
      else{
        cout << -1 << endl;
        exit(0);
      }
    }
  }

  cout << res << endl;

}
