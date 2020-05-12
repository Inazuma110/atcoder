#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <cstdio>

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
  ll s;
  cin >> s;
  ll x1, x2, x3, y1, y2, y3;
  x1 = 0;
  y1 = 0;
  x3 = 0;
  y2 = 0;
  x2 = 0;
  y3 = 0;

  x2 = (MOD-7);
  y2 = 1;

  ll mod = s % (MOD-7);
  ll div = s / (MOD-7);

  y3 = div + 1;
  x3 = (MOD-7) - mod;

  if(s == 1000000000000000000ll){
    x3 = 0;
    y3 = x2;
    y2 = 0;
  }

  printf("%lld %lld %lld %lld %lld %lld", x1, y1, x2, y2, x3, y3);
}
