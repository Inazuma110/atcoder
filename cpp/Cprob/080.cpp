#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define itn int
typedef long long ll;
typedef pair<int,int> p;

vector<vector<int>> other(100,vector<int>(10, 0));
vector<vector<int>> store(100,vector<int>(11, 0));
int ans = 0;

vector<int> tmp(10, 0);

void slove()
{
  int score = 0;
  for (int i = 0; i < 100; i++){
    for (int j = 0; j < 10; j++){
      /* code */
    }
  }
  ans = max(score, ans);
}

void dfs(int pos)
{
  if(pos == 10)
  {
    slove();
    return;
  }
  else
  {
    tmp[pos] = 0;
    dfs(pos+1);
    tmp[pos] = 1;
    dfs(pos+1);
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 10; j++){
      cin >> other[i][j];
    }
    for (int j = 0; j < 11; j++){
      cin >> store[i][j];
    }
  }
  dfs(0);
  dfs(1);
  cout << ans << endl;
}
