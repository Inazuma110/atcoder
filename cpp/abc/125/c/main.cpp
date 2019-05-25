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

  int n;
  cin >> n;
  vector<int> v(n);
  vector<ll> left(n);
  vector<ll> right(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  left[0] = v[0];
  for (int i = 1; i < n; i++) {
    left[i] = gcd(v[i], left[i-1]);
  }
  right[n-1] = v[n-1];
  for (int i = n-2; i >= 0; i--) {
    right[i] = gcd(right[i+1], v[i]);
  }


  // print(left);
  // print(right);
  ll res = max(right[1], left[n-2]);
  for (int i = 1; i < n-1; i++) {
    res = max(res, gcd(left[i-1], right[i+1]));
  }

  cout << res << endl;
}
