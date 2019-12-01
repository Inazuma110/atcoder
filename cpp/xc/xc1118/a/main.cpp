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
  ll res = LLONG_MAX;
  for (int i = 1; i < n; i++) {
    ll tmp = 0;
    string a = to_string(i);
    string b = to_string(n - i);
    for(auto k : a){
      tmp += k - '0';
    }
    for(auto k : b){
      tmp += k - '0';
    }
    res = min(res, tmp);
  }
  cout << res << endl;
}
