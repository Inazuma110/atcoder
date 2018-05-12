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
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  for (int i = 0; i < m; i++){
    cin >> sw[i].first;
    cin >> sw[i].second;
  }

  return 0;
}
