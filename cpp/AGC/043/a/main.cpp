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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  rep(i, h) cin >> v[i];

  queue<pair<p, int>> q;
  q.push({{0, 0}, v[0][0] == '.' ? 0 : 1});
  vector<vector<int>> dp(h, vector<int>(w, INT_MAX));
  // dp[0][0] = (v[0][0] == '.') ? 0 : 1;

  while(!q.empty()){
    int y = q.front().first.first;
    int x = q.front().first.second;
    int num = q.front().second;
    q.pop();
    // cout << y << ' ' << x << endl;
    if(dp[y][x] <= num){
      continue;
    }
    chmin(dp[y][x], num);

    if(y+1 < h) {
      q.push({{y+1, x}, v[y][x] == '.' && v[y+1][x] == '#' ? num+1 : num});
    }
    if(x+1 < w){
      q.push({{y, x+1}, v[y][x] == '.' && v[y][x+1] == '#' ? num+1 : num});
    }
  }
  cout << dp[h-1][w-1] << endl;
}
