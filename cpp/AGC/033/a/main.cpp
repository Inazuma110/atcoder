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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  for (int i = 0; i < h; i++){
    cin >> v[i];
  }

  int res = 0;

  queue<p> q;
  vector<int> count(h * w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if(v[i][j] == '#'){
        q.push({i, j});
        count[0]++;
      }
    }
  }

  int now_count = 0;
  while(q.size() != 0){
    int ny = q.front().first;
    int nx = q.front().second;
    q.pop();
    if(ny - 1 >= 0 && v[ny-1][nx] == '.'){
      q.push({ny-1, nx});
      v[ny-1][nx] = '#';
      count[now_count+1]++;
    }
    if(ny + 1 < h && v[ny+1][nx] == '.'){
      q.push({ny+1, nx});
      v[ny+1][nx] = '#';
      count[now_count+1]++;
    }
    if(nx - 1 >= 0 && v[ny][nx-1] == '.'){
      q.push({ny, nx-1});
      v[ny][nx-1] = '#';
      count[now_count+1]++;
    }
    if(nx + 1 < w && v[ny][nx+1] == '.'){
      q.push({ny, nx+1});
      v[ny][nx+1] = '#';
      count[now_count+1]++;
    }
    count[now_count]--;
    if(count[now_count] == 0){
      now_count++;
      if(count[now_count] == 0) break;
      res++;
    }

  }

  cout << res << endl;

}
