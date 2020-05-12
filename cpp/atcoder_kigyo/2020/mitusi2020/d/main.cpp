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

long long comb(ll n, ll r) {
  if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
  long long ans = 1;

  for(int i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;

  ll res = 0;
  for (int i = 0; i < 1000; i++) {
    string tmp = to_string(i);
    if(i < 10) tmp = "00" + tmp;
    else if(i < 100) tmp = "0" + tmp;

    int j = 0;
    for (int k = 0; k < n; k++) {
      if(tmp[j] == s[k]) j++;
      if(j == 3){
        res++;
        break;
      }
    }
  }
  cout << res << endl;
}
