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


long double logn(int base, int tv)
{
  return log(tv) / log(base);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  long double n, k;
  cin >> n >> k;
  long double res = 0;

  for (int i = 1; i <= n; i++) {
    int tmp = i;
    long double p = 1;
    while(tmp < k){
      tmp *= 2;
      p *= 0.5;
    }
    res += p;
  }
  res /= n;
  printf("%.10Lf\n",res);


}
