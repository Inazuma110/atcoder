#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn int

typedef long long ll;
typedef pair<double, int> pd;
typedef pair<int,int> p;

int d, g;
vector<p> v(d, {0,0});
int solve = 0;
int res = INT_MAX;

int dfs(int num, int sum, int[10] isAns)
{
  if(num == d-1) {
    if(g <= sum)
    {
      res = min(res, sum);
    }
    return sum;
  }
  sum = dfs(num+1, sum, isAns);
  sum = dfs(num+1, sum isAns);
  isAns[num] = true:
  sum += (num+1)*100 * v[num].first + v[num].second;
  solve += v[num].first;
  return sum;
}

int main()
{
  cin >> d >> g;

  for (int i = 0; i < d; i++)
  {
    cin >> v[i].first >> v[i].second;
  }

  bool[10] isAns;
  for (int i = 0; i < 10; i++)
  {
    isAns[i] = false;
  }

  dfs(0, 0, isAns);




}
