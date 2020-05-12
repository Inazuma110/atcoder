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
  int n, k;
  cin >> n >> k;
  vector<int> w(n);
  rep(i, n) cin >> w[i];

  auto is = [&](ll lim){
    int now = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
      if(w[i] > lim) return false;
      now += w[i];
      if(now > lim){
        now = 0;
        b++;
        i--;
      }
    }
    if(now > 0) b++;
    // cout << b << endl;
    if(b <= k) return true;
    else return false;
  };

  ll ok = LLONG_MAX/2ll;
  ll ng = -1;
  while(ok - ng > 1){
    ll mid = (ok+ng) / 2ll;
    if(is(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;

}
