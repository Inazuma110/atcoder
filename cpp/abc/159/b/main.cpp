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
  int n = int(s.size());
  bool flag = true;
  for(int i = 0; i < n/2; i++){
    if(s[i] != s[n-1-i]) flag = false;
  }

  string tmp2 = s.substr(0, (n-1)/2);
  int n2 = int(tmp2.size());
  for(int i = 0; i < n2/2; i++){
    if(s[i] != s[n2-1-i]) flag = false;
  }
  string tmp3 = s.substr((n+2)/2);
  n = int(tmp2.size());
  for(int i = 0; i < n/2; i++){
    if(s[i] != s[n-1-i]) flag = false;
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
