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
  int n, m, q;
  cin >> n >> m >> q;
  vector<p> lr(m);
  for (int i = 0; i < m; i++) {
    cin >> lr[i].first >> lr[i].second;
    // lr[i].first--;
    // lr[i].second--;
  }
  vector<p> query(q);
  for (int i = 0; i < q; i++) {
    cin >> query[i].first >> query[i].second;
    // query[i].first--;
    // query[i].second--;
  }
  vector<vector<int>> area(n+1, vector<int>(n+1, 0));
  for (int i = 0; i < m; i++) {
    int start = lr[i].first;
    int goal = lr[i].second;
    area[start][goal]++;
  }
  // print(area);

  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      area[i][j] += area[i][j-1];
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      area[j][i] += area[j-1][i];
    }
  }

  // print(area);
  for(auto a : query){
    int minv = min(a.first, a.second);
    int maxv = max(a.first, a.second);
    int res = area[maxv][maxv] + area[minv-1][minv-1];
    // cout << res << endl;
    res -= (area[maxv][minv-1] + area[minv-1][maxv]);
    cout << res << endl;
    // cout << "====" << endl;
  }
}
