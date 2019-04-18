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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;
  long double neck = min({a, b, c, d, e});
  ll res = 4;
  res += ceil(double(n) / neck);
  cout << res << endl;
}
