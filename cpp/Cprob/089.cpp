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
  int n;
  cin >> n;
  vector<string> v;
  vector<ll> count(5,0);
  for (int i = 0; i < n; i++)
  {
    string tmp;
    cin >> tmp;
    v.push_back(tmp);
    if (v[i][0] == 'M')
    {
      count[0]++;
    }else if (v[i][0] == 'A')
    {
      count[1]++;
    }else if (v[i][0] == 'R')
    {
      count[2]++;
    }else if (v[i][0] == 'C')
    {
      count[3]++;
    }else if (v[i][0] == 'H')
    {
      count[4]++;
    }
  }
  int kindCount = 0;
  for (int i = 0; i < 5; i++)
  {
    if (count[i] >= 1)
    {
      kindCount++;
    }
  }

  ll result = 1;
  int calc = kindCount;
  for (int i = 0; i < 3; i++)
  {
    result *= calc;
    calc--;
  }

  result /= 6;
  ll hoge = result;
  ll hoge2 = (kindCount - 1) * (kindCount - 2);
  hoge2 /= 2;
  hoge -= hoge2;

  // cout << hoge << endl;
  for (int i = 0; i < 5; i++)
  {
    if (count[i] != 0)
    {
      result *= count[i];
    }
  }


  for (int i = 0; i < 5; i++)
  {
    if (count[i] >= 2)
    {
      result -= (hoge * (count[i] - 1));
    }
  }





  cout << result << endl;
}
