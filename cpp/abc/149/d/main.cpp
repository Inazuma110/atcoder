#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

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
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  ll res = 0;
  map<char, int> mp;
  mp['s'] = r;
  mp['p'] = s;
  mp['r'] = p;

  vector<bool> free(n, true);
  rep(i, n){
    if(i < k) {
      res += mp[t[i]];
      free[i] = false;
    } else{
      if(t[i] != t[i-k]){
        res += mp[t[i]];
        free[i] = false;
      }else{
        if (free[i-k]){
          res += mp[t[i]];
          free[i] = false;
        }else{
          free[i] = true;
        }
      }
    }
    // cout << res << endl;
  }

  cout << res << endl;

}
