#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> p;


int main(void)
{
  int n;
  cin >> n;
  vector<int> v(n, 0);
  vector<int> vTmp(n, 0);
  for (int i = 0; i < n; i++){
    cin >> v[i];
    vTmp[i] = v[i];
  }

  int res1 = 0;
  // int res2 = 0;
  for (int i = 0; i < n; i++){
    if (v[i] == i+1 && v[n-1-i] == n-i) {
      res1++;
      // vTmp.erase(v.end() - i);
      continue;
    }
    if (v[i] != i+1) {
      // res1 = v[i] + i;
      res1 = n - v[n-1-i];
      // cout << min(res1, res2) << endl;
      cout << res1 << endl;
      // cout << res2 << endl;

      break;
    }
  }


  // for (int i = 0; i < n; i++){
  //   res =
  // }


  return 0;
}
