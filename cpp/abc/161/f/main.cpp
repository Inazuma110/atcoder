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

ll n;
vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  ll res = 0;
  for (ll k = 2; k*k <= n+1; ++k) {
    ll tmp = n;
    int count = 0;
    while(true){
      // cout << tmp << endl;
      if(tmp <= 0 || count >= 10) break;
      else if(tmp == 1){
        res++;
        break;
      }
      if(tmp % k == 0) tmp = tmp / k;
      else {
        tmp = tmp % k;
        count++;
      }
    }
  }

  vector<int64_t> ya = divisor(n-1);
  res += int(ya.size()) / 2;
  res++;

  cout << res << endl;
}
