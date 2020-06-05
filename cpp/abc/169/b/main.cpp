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
  ll n;
  cin >> n;
  vector<ll> v(n);
  bool flag = false;
  rep(i, n){
    cin >> v[i];
    if(v[i] == 0) flag = true;
  }
  cpp_int res = 1;
  // print(v);

  rep(i, n){
    res *= v[i];
    if(res > cpp_int(1000000000000000000)){
      res = -1;
      break;
    }
  }
  if(flag) cout << 0 << endl;
  else cout << res <<endl;
}
