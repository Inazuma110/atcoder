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
  vector<double> v(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }


  vector<double> maxv(50000, 100000);

  int sum_time = 0;
  for (int i = 0; i < n; i++) {
    t[i] *= 2;
    for (int j = sum_time; j <= sum_time + t[i]; j++) {
      maxv[j] = min(maxv[j], v[i]);
    }
    sum_time += t[i];
  }
  maxv[0] = maxv[sum_time] = 0;

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < sum_time; i++) {
      maxv[i+1] = min(maxv[i+1], maxv[i]+0.5);
    }
    for (int i = sum_time-1; i >= 0; i--) {
      maxv[i] = min(maxv[i+1] + 0.5, maxv[i]);
    }
  }

  double res = 0;
  for (int i = 0; i < sum_time; i++) {
    res += double(maxv[i+1] + maxv[i]);
  }
  cout << res / 4 << endl;
}
