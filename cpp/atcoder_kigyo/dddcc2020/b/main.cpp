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

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v(n);
  ll sum = 0;
  rep(i, n) {
    cin >> v[i];
    sum += v[i];
  }
  ll tmp1 = 0;
  ll res = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    tmp1 += v[i];
    res = min(res, abs(tmp1 - (sum - tmp1)));
  }

  cout << res << endl;


}
