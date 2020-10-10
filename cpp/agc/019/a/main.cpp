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


int main(){
  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  if(n == 1){
    cout << min({q*4, h*2, s}) << endl;
    return 0;
  }

  q *= 8;
  h *= 4;
  s *= 2;



  ll res1 = (n / 2) * q;
  if(n % 2 == 1) res1 += q / 2;
  ll res2 = (n / 2) * h;
  if(n % 2 == 1) res2 += h / 2;
  ll res3 = (n / 2) * s;
  if(n % 2 == 1) res3 += s / 2;
  ll res4 = (n / 2) * d;
  if(n % 2 == 1) res4 += min({q, h, s}) / 2;

  cout << min({res1, res2, res3, res4}) << endl;
}

