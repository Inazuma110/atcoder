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
  vector<int> t(n);
  vector<int> v(n);
  int sum_time = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    sum_time += t[i];
  }
  sum_time++;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<double> maxv(2*n, 0);

  int now_time = 0;
  for (int i = 1; i < 2*n; i++) {
    maxv[i] = min(maxv[i-1] + 0.5, v[i]);
  }



}
