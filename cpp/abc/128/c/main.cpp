#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
// typedef pair<int, int> p;

int n, m;
vector<int> k;
vector<vector<int>> s;
vector<int> p;
int res = 0;


void dfs(int a, vector<bool> tmp){
  // print(tmp);
  if(a == n){
    int count1 = 0;
    for (int x1 = 0; x1 < int(s.size()); x1++) {
      int count2 = 0;
      for(auto x2 : s[x1]){
        if(tmp[x2]){
          count2++;
        }
      }
      // cout << count2 << endl;
      if(count2 % 2 == p[x1]) count1++;
    }
    if(count1 == m) res++;
    // cout << "====" << endl;
    return;
  }else{
    tmp[a] = true;
    dfs(a+1, tmp);
    tmp[a] = false;
    dfs(a+1, tmp);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  k = vector<int> (m);
  s = vector<vector<int>> (m);

  for (int i = 0; i < m; i++) {
    cin >> k[i];
    s[i] = vector<int> (k[i]);
    for (int j = 0; j < k[i]; j++) {
      cin >> s[i][j];
      s[i][j]--;
    }
  }

  p = vector<int> (m);
  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }
  vector<bool> tmp(n, false);
  dfs(0, tmp);
  cout << res << endl;

}
