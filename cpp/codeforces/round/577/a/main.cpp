#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
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
  vector<string> v(n);
  vector<int> score(m);
  rep(i, n) cin >> v[i];
  rep(i, m) cin >> score[i];

  vector<map<char, int>> count(m);
  vector<int> res(m, -1);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      count[i][v[j][i]]++;
    }
    for(auto a : count[i]){
      res[i] = max(res[i], a.second);
    }
  }
  // print(count);
  // print(res);
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    ans += score[i] * res[i];
  }
  cout << ans << endl;
}
