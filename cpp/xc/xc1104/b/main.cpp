#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
//
// using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<p> v(m);
  vector<vector<int>> rel(n);

  for (int i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
    v[i].first--; v[i].second--;
    rel[v[i].first].push_back(v[i].second);
    rel[v[i].second].push_back(v[i].first);
  }

  for (int i = 0; i < n; i++) {
    int res = 0;
    for (int j = 0; j < int(rel[i].size()); j++) {
      int friendnum = rel[i][j];
      for (int k = 0; k < int(rel[friendnum].size()); k++) {
        if(i == rel[friendnum][k]) continue;
        for (int l = 0; l < int(rel[i].size()); l++) {

        }
        if(find(ALL(rel[i]), rel[friendnum][k]) == rel[i].end()) res++;
      }
    }
    cout << res << endl;
  }
}
