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
map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 2; i <= n; ++i) {
    auto v = prime_factor(i);
    for(auto a : v){
      mp[a.first] += a.second;
    }
  }
  ll four = 0, two = 0;
  for (int i = 2; i <= n; ++i) {
    if(mp[i] >= 4) four++;
    else if(mp[i] >= 2) two++;
  }
  // print(mp);
  // cout << four << endl;
  // cout << two << endl;

  ll res = 0;
  if(four >= 2 && two >= 1) res += (four * (four-1)) / 2* two;
  if(four >= 3) res += four * ((four-1) * (four - 2)) / 2;

  cout << res << endl;
}
