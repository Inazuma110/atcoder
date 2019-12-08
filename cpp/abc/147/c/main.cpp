#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
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

int n;
vector<vector<p>> xy;

ll res = 0;

ll counter(vector<int> v){
  int count = 0;
  for(auto a : v) if(a == 1) count++;
  return count;
}

void dfs(int step, vector<int> beta){
  if(step == n){
    for (int i = 0; i < n; i++) {
      if(beta[i] == 0) continue;
      for (int j = 0; j < int(xy[i].size()); j++) {
        int target = xy[i][j].first;
        int is = xy[i][j].second;

        if(beta[target] != is) return;
      }
    }

    res = max(counter(beta), res);
    return;
  }

  dfs(step+1, beta);
  beta[step] = 0;
  dfs(step+1, beta);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<int> v(n);
  xy = vector<vector<p>> (n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    xy[i] = vector<p> (v[i]);
    for (int j = 0; j < v[i]; j++) {
      cin >> xy[i][j].first >> xy[i][j].second;
      xy[i][j].first--;
    }
  }

  dfs(0, vector<int> (n, 1));

  cout << res << endl;

}
