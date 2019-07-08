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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  vector<vector<int>> count(h+1, vector<int> (w+1, 1));
  vector<vector<bool>> visited(h+1, vector<bool> (w+1, false));

  vector<bool> flags(w, false);
  for (int i = 0; i < h; i++) {
    cin >> v[i];
    for (int j = 0; j < w; j++) {
      if(i == 0 && j == 0) continue;

      if(v[i][j] == '#') count[i][j] = 0;
      else{
        if(i == 0 && count[i][j-1] == 0) count[i][j] = 0;
        else if(j == 0 && count[i-1][j] == 0) count[i][j] = 0;
        else if(i >= 1 && j >= 1 && (count[i-1][j] == 0 || count[i][j-1] == 0)) count[i][j] = 0;
      }
    }
  }
  // print(v);
  // print(count);

  //
  // queue<p> q;
  // q.push({0, 0});
  // // visited[0][0] = true;
  // while(!q.empty()) {
  //   int ny = q.front().first;
  //   int nx = q.front().second;
  //   cout << ny << " : " << nx << endl;
  //   q.pop();
  //   for (int i = 0; i < 4; i++) {
  //     v[ny][nx] = '#';
  //     int next_x = nx + dx[i];
  //     int next_y = ny + dy[i];
  //     visited[ny][nx] = true;
  //     if(next_x >= 0 && next_x < w && next_y >= 0 && next_y < h){
  //       // cout << next_y << " : " << next_x << endl;
  //       if(v[next_y][next_x] == '.'){
  //         q.push({next_y, next_x});
  //         if(visited[next_y][next_x]){
  //           count[next_y][next_x] += count[ny][nx];
  //           count[next_y][next_x] %= MOD;
  //         }else{
  //           count[next_y][next_x] = count[ny][nx];
  //           visited[next_y][next_x] = true;
  //         }
  //       }
  //     }
  //   }
  // }
  //
  // print(count);
  // print(visited);
  // cout << count[h-1][w-1] << endl;

  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      if(v[i][j] == '.') count[i][j] = (count[i-1][j] + count[i][j-1]) % MOD;
      else count[i][j] = 0;
    }
  }

  cout << count[h-1][w-1] << endl;
}
