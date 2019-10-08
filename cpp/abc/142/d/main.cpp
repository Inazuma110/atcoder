#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
//
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


vector<pair<ll, int>> factoring(ll a){
  vector<pair<ll, int>> v;
  for (int i = 2; i <= a; i++) {
    if(a % i == 0){
      int count = 0;
      while(a % i == 0){
        count++;
        a /= i;
      }
      v.push_back({i, count});
    }
  }
  return v;
}

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  else return gcd(b, a % b);
  // return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  ll g = gcd(a, b);
  return a / g * b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a, b;
  cin >> a >> b;
  ll x = gcd(a, b);
  if(x == 1){
    cout << 1 << endl;
    return 0;
  }
  vector<ll> tmp;
  for (ll i = 1; i*i <= x; i++) {
    if(x % i == 0){
      tmp.push_back(i);
      tmp.push_back(x / i);
    }
  }

  // print(tmp);
  sort(ALL(tmp));
  ll res = 1;
  ll mul = 1;
  for(ll a1 : tmp){
    if(a1 == 1) continue;
    if(gcd(a1, mul) != 1) continue;
    // cout << a1 << endl;
    res++;
    mul *= a1;
  }
  // vector<pair<ll, int>> tmp = factoring(x);
  cout << res << endl;
}
