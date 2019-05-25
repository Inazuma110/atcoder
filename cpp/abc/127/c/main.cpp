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
  int n, m;
  cin >> n >> m;
  int minv = -1;
  int maxv = INT_MAX;
  vector<p> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
    minv = max(minv, v[i].first);
    maxv = min(maxv, v[i].second);
  }
  int res = max(maxv - minv + 1, 0);
  cout << res << endl;
}
