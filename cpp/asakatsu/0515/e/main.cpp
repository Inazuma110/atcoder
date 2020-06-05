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
  int h, w, d;
  cin >> h >> w >> d;
  map<int, p> mp;
  vector<vector<int>> v(h, vector<int> (w));
  rep(i, h) rep(j, w){
    cin >> v[i][j];
    mp[v[i][j]] = {i, j};
  }
  int q;
  cin >> q;
  vector<p> qs(q);
  rep(i, q) cin >> qs[i].first >> qs[i].second;
  vector<int> dp(h*w+10);

  rep(i, d){
    int now = i+1;
    ll cost = 0;
    while(now <= h*w){
      dp[now] = cost;
      int next = now + d;
      int y = mp[next].first;
      int x = mp[next].second;
      int b = mp[now].first;
      int a = mp[now].second;
      cost += abs(y - b) + abs(x - a);
      now = next;
    }
  }
  // print(dp);

  rep(i, q){
    int now = qs[i].first;
    int goal = qs[i].second;
    cout << dp[goal] - dp[now] << endl;
  }
}
