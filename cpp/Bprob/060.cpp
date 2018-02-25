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
  int a, b, c;
  cin >> a >> b >> c;
  ll tmp = 1;

  if (a == 1)
  {
    cout << "YES" << endl;
    return 0;
  }

  int i = 1;
  // for (int i = 1; i <= 10; i++)
  while (tmp < (c * 10) + (a * 10))
  {
    tmp = i * a;
    cout << tmp << endl;
    if (tmp % b == c)
    {
      cout << "YES" << endl;
      return 0;
    }
    i++;
  }
  cout << "NO" << endl;
}
