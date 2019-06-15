#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;

vector<vector<int>> dp(10000, vector<int> (10000, 0));
// vector<int> dp(10000, -1);
string s;
int x, y;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int tmp = 0;
queue<p> q;

void solve(){
  p now = {0, 0};
  bool flag = false;
  for(auto a : s){
    while(true) {
      p next = q.front();
      int nx = next.first;
      int ny = next.second;
      if(a == 'T'){
        q.push({nx+tmp%4, ny+tmp%4});
      }else{
        q.pop();
        dp[nx+tmp%4][ny+tmp%4] = 1;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  q.push({0, 0});
  cin >> s;
  cin >> x >> y;
  dp[0][0] = 1;
  solve();

}
