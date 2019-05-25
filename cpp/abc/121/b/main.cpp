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
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  ll res = 0;
  vector<vector<int>> vv(n,vector<int>(m));

  for (int i = 0; i < n; i++) {
    int score = c;
    for (int j = 0; j < m; j++) {
      cin >> vv[i][j];
      score += b[j] * vv[i][j];
    }
    res += (score > 0);
  }
  cout << res << endl;

}
