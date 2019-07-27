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
  int n;
  cin >> n;
  vector<int> a(n+1);
  vector<int> b(n);
  for (int i = 0; i < n+1; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  ll res = 0;
  for (int i = 0; i < n; i++) {
    res += min(a[i], b[i]);
    b[i] = max(0, b[i] - a[i]);
    res += max(0, min(a[i+1], b[i]));
    a[i+1] = max(0, a[i+1] - b[i]);
  }

  cout << res << endl;
}
