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
  long double n, d;
  cin >> n >> d;
  vector<vector<long double>> x(n, vector<long double> (d, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      cin >> x[i][j];
    }
  }

  ll res = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      long double dist = 0;
      for (int k = 0; k < d; k++) {
        dist += abs(x[i][k] - x[j][k]) * abs(x[i][k] - x[j][k]);
      }
      dist = pow(dist, 0.5);
      // cout << dist << endl;
      if(ceil(dist) == floor(dist)) res++;
    }
  }

  cout << res << endl;
}
