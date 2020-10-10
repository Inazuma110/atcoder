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
  int q;
  cin >> s >> q;
  bool is_rev = 0;
  string tmp1 = "", tmp2 = "";
  while(q){
    q--;
    int t;
    cin >> t;
    if(t == 1) is_rev = !is_rev;
    else{
      int f;
      string c;
      cin >> f >> c;
      if(is_rev){
        if(f==1) tmp2 += c;
        else tmp1 += c;
      }else{
        if(f==1)tmp1 += c;
        else tmp2 += c;
      }
    }
  }

  if(!is_rev){
    reverse(ALL(tmp1));
    cout << tmp1 << s << tmp2 << endl;
  }
  else {
    reverse(ALL(tmp2));
    reverse(ALL(s));
    cout << tmp2 << s << tmp1 << endl;
  }
}
