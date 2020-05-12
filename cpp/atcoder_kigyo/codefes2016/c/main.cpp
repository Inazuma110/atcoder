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
  int k;
  cin >> s >> k;
  int n = int(s.size());
  rep(i, n){
    int t = s[i] - 'a';
    t = 26 - t;
    if(k >= t && s[i] != 'a'){
      s[i] = 'a';
      k -= t;
    }
  }
  k %= 26;

  s[n-1] += k;
  if(s[n-1] > 'z') s[n-1] -= 26;

  cout << s << endl;
}
