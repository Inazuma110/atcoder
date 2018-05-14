#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> p;


int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> v(n, 0);
  vector<p> sw(m, {0,0});
  vector<vector<int>> vv(n,vector<int>(n,0));
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  for (int i = 0; i < m; i++){
    cin >> sw[i].first;
    cin >> sw[i].second;
  }

  for(p i : sw){
    vv[i.first-1][i.second-1] = 1;
    vv[i.second-1][i.first-1] = 1;
    vv[i.first-1][i.first-1] = 1;
    vv[i.second-1][i.second-1] = 1;
  }

  // for(vector<int> i : vv){
  //   for(int j : i){
  //     cout << j << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  int res = 0;
  for (int i = 0; i < n; i++){
    if ((v[i] - 1) == i) {
      res++;
    }else{
      for (int j = 0; j < n; j++){
        if (vv[j][v[i]-1] == 1 && vv[j][i] == 1) {
          res++;
          break;
        }
      }
    }
  }
  cout << res << endl;


  return 0;
}
