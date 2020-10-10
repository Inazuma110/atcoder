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
  int n;
  cin >> n;
  vector<string> v(n);
  ll res = 0;
  ll begin = 0, end = 0;
  ll tmp = 0;
  rep(i, n){
    cin >> v[i];
    auto size = v[i].size();
    rep(j, size-1){
      if(v[i][j] == 'A' && v[i][j+1] == 'B') res++;
    }
    if(v[i][size-1] == 'A' && v[i][0] == 'B') tmp++;
    else if(v[i][size-1] == 'A') end++;
    else if(v[i][0] == 'B') begin++;
  }
  if(begin == 0 && end == 0 && tmp > 0) tmp--;

  // cout << begin << ' ' << end << ' ' << tmp << endl;
  // cout << res << endl;

  res += min(begin+tmp, end+tmp);
  cout << res << endl;
}
