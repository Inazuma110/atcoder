#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;

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

  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  a--;
  ll x = lcm(c, d);
  ll tmp1 = (b / x) - (a / x);
  ll tmp2 = (b / c) - (a / c);
  ll tmp3 = (b / d) - (a / d);
  cout << (b-a) - (tmp2+tmp3-tmp1) << endl;
}
