#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

int main(){
  int n;
  cin >> n;
  vector<double> x(n, 0);
  vector<string> u(n, "@");
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> u[i];
  }
  double res = 0;
  for (int i = 0; i < n; i++) {
    if(u[i] == "JPY") res += x[i];
    else res += x[i] * 380000;
  }

  printf("%lf\n",res);

}
