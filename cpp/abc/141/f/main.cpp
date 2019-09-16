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
  rep(i, n) cin >> v[i];
  sort(RALL(v));

  ll sum1 = 0, sum2 = 0;
  rep(i, n){
    if(v[i] % cpp_int(2) == 0){
      sum1 ^= v[i];
    }else{
      sum2 ^= v[i];
    }
  }
  int mode = -1;
  if(sum1 == 0) mode = 0;
  else if(sum2 == 0) mode = 1;

  if(mode == -1){
    cout << sum1 + sum2 << endl;
    return 0;
  }

  sum1 = 0, sum2 = 0;
  if(mode == 0){
    rep(i, n){
      if(i == 1){
        sum1 ^= v[i];
      }else{
        sum2 ^= v[i];
      }
    }
  }else{
    rep(i, n){
      if(i == 0){
        sum1 ^= v[i];
      }else{
        sum2 ^= v[i];
      }
    }
  }
  cout << sum1 + sum2 << endl;
}
