#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <climits>
#include <iterator>
#include <vector>

using boost::multiprecision::cpp_int;
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

int h, w;
vector<string> v;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int res = 0;

int s(int sy, int sx){
  queue<pair<p, int>> st;
  st.push({{sy, sx}, 0});
  int vis[h][w];
  rep(i, h)rep(j, w) vis[i][j] = false;
  vis[sy][sx] = true;

  while(!st.empty()){
    int y = st.front().first.first;
    int x = st.front().first.second;
    int d = st.front().second;

    st.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      int nd = d+1;
      if(ny < 0 || nx < 0) continue;
      if(ny >= h || nx >= w) continue;
      if(v[ny][nx] == '#') continue;
      // cout << ny << ' ' << nx << endl;

      if(!vis[ny][nx]){
        vis[ny][nx] = true;
        st.push({{ny, nx}, nd});
        res = max(res, nd);
      }
    }

  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w;
  v = vector<string> (h);
  rep(i, h) cin >> v[i];

  for (int sy = 0; sy < h; sy++) {
    for (int sx = 0; sx < w; sx++) {
      if(v[sy][sx] == '#') continue;
      res = max(s(sy, sx), res);
    }
  }

  cout << res << endl;
}
