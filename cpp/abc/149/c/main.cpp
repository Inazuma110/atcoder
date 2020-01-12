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

bool is_prime(ll x){
  for (int i = 2; i * i <= x; i++) {
    if(x % i == 0){
      // cout << x << endl;
      return true;
    }
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x;
  cin >> x;
  for (int i = x; ; i++) {
    if(!is_prime(i)){
      cout << i << endl;
      break;
    }
  }
}
