#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if(v[i] == k){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  sort(all(v));
  int maxv = v[n-1];

  ll tmp = v[0];
  for (int i = 0; i < n; i++) {
    tmp = gcd(tmp, v[i]);
  }

  if(tmp == 1 && maxv >= k){
    cout << "POSSIBLE" << endl;
  }else if(tmp != 1 && k % tmp == 0 && maxv >= k){
    cout << "POSSIBLE" << endl;
  }else{
    cout << "IMPOSSIBLE" << endl;
  }
}
