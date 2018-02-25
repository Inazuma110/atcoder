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
  int k,s;
  cin >> k >> s;
  int count;
  for (int x = 0; x <= k; x++)
  {
    for (int y = 0; y <= k; y++)
    {
      // for (int z = 0; z <= (s - x - y); z++)
      for (int z = 0; z <= k; z++)
      {
        if (x + y + z == s)
        {
          count++;
        }
      }
    }
  }
  cout << count << endl;
}
