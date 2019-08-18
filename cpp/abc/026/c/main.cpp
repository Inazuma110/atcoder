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
typedef pair<ll, ll> p;

int n;
vector<int> v;
vector<int> salary;
vector<vector<int>> rel;

int dfs(int num){
  if(rel[num].size() == 0) return salary[num] = 1;
  int minv = INT_MAX;
  int maxv = -1;
  for(auto buka : rel[num]){
    if(salary[buka] == -1){
      int s = dfs(buka);
      minv = min(minv, s);
      maxv = max(maxv, s);
    }
  }
  return salary[num] = maxv + minv + 1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  v = vector<int>(n-1);
  salary = vector<int>(n, -1);
  rel = vector<vector<int>> (n);
  for (int i = 0; i < n-1; i++) {
    cin >> v[i];
    v[i]--;
    rel[v[i]].push_back(i+1);
  }
  // print(rel);

  dfs(0);
  cout << salary[0] << endl;
}
