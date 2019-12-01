#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  // map<p, bool> checked;
  bool checked[2000][2000];
  // rep(i, 2000) rep(j, 2000) checked[i][j] = false;
  queue<pair<p, int>> q;
  int count = 0;
  rep(i, h){
    cin >> v[i];
    rep(j, w){
      if(v[i][j] == '#'){
        q.push({{i, j}, count});
        checked[i][j] = true;
      }
    }
  }

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  int res = 0;
  while(!q.empty())
  {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int count = q.front().second;
    res = count;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny >= 0 && nx >= 0 && ny < h && nx < w){
        if(!checked[ny][nx] && v[ny][nx] == '.'){
          v[ny][nx] = '#';
          checked[ny][nx] = true;
          q.push({{ny, nx}, count+1});
        }
      }
    }
  }
  // print(v);
  cout << res << endl;



}
