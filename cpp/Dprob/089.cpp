using namespace std;

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <limits>
#include <climits>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <numeric>
typedef long long ll;
typedef pair<int,int> p;

int main()
{
  int h, w, d;
  cin >> h >> w >> d;
  vector<vector<int>> vv(h,vector<int>(w,0));
  // vector<p> position;
  map<int, p> mp;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> vv[i][j];
    }
  }
  int q;
  cin >> q;
  vector<int> l(q,0);
  vector<int> r(q,0);
  for (int i = 0; i < q; i++)
  {
    cin >> l[i];
    cin >> r[i];
  }

  vector<int> cost(h * w - d, 0);

  for (int i = 0; i < h * w - d; i++)
  {
    // cost[i] =
  }


}
