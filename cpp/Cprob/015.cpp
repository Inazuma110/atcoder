#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

int n , k;

bool dfs(int num,int val){
  for(int i = 0; i < k; i++)
  {
    if(num != n) dfs(num+1,val^vv[i]);
    if (num == n && val == 0) return true;
  }

}

int main()
{
  // input & declare
  int result = 0;
  cin >> n >> k;
  int tmp;
  std::vector<vector<int>> vv(n,vector<int>(k,0));
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < k; j++)
    {
      cin >> vv[i][j];
    }
  }

  // process


  //output

}
