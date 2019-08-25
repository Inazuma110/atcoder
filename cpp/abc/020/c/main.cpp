#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;

int h, w, t;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w >> t;
  int start, goal;

  vector<string> field(h);
  for (int i = 0; i < h; i++) {
    cin >> field[i];
    for (int j = 0; j < w; j++) {
      if(field[i][j] == 'S'){
        start = i * w + j;
      }
      if(field[i][j] == 'G'){
        goal = i * w + j;
      }
    }
  }

  ll lb = 0, ub = t + 1;
  while(ub - lb > 1) {
    ll mid = (lb + ub) / 2;
    ll d[h*w][h*w];
    rep(i, h*w) rep(j, h*w){
      d[i][j] = (i == j) ? 0 : INT_MAX;
    }

    rep(i, h) rep(j, w){
      rep(k, 4){
        int x = i + dx[k], y = j + dy[k];
        if(x < 0 || x >= h || y < 0 || y >= w) continue;
        ll ins = (field[x][y] == '#') ? mid : 1;
        d[i*w + j][x*w + y] = ins;
      }
    }

    rep(k, h*w) rep(i, h*w) rep(j, h*w) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    if(d[start][goal] <= t) lb = mid;
    else ub = mid;
  }

  cout << lb << endl;


}
