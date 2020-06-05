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


int get_f(int v){
  return to_string(v)[0] - '0';
}

int get_l(int v){
  return to_string(v)[to_string(v).size()-1] - '0';
}

int get_keta(int v){
  return int(to_string(v).size());
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
    // dp_ij := n以下で先頭i尻jな値の個数
  vector<vector<int>> dp(20, vector<int> (20, 0));

  rep(i, n+1){
    int f = get_f(i);
    int l = get_l(i);
    dp[f][l]++;
  }

  int res = 0;
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      res += dp[i][j] * dp[j][i];
    }
  }

  cout << res << endl;
}
