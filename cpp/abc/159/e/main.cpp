#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/type_traits/detail/mp_defer.hpp>
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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;

int h, w, k;
vector<vector<int>> dp;
ll res = 0;

int c[10][1005];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> h >> w >> k;
  vector<string> v(h);
  rep(i, h) cin >> v[i];
  rep(div, 1<<(h-1)){
    int g = 0;
    vector<int> id(h);
    rep(i, h){
      id[i] = g;
      if(div >> i & 1){ g++; }
    }
    g++;

    rep(i,g)rep(j,w) c[i][j] = 0;
    rep(i, h) rep(j, w) c[id[i]][j] += (v[i][j] == '1');
    ll num = g - 1;
    vector<int> now(g);
    auto add = [&](int j){
      rep(i, g) now[i] += c[i][j];
      rep(i, g) if(now[i] > k) return false;
      return true;
    };
    rep(j, w) {
      if(!add(j)){
        num++;
        now = vector<int>(g);
        if(!add(j)){
          num = INT_MAX;
          break;
        }
      }
    }
    res = min(res, num);
  }
  cout << res << endl;
}

