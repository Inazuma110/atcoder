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

int dp[3][100];


// int money(int kab){
// }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> is_high(n);
  rep(i, n) cin >> v[i];
  dp[0][0] = 1000;
  dp[1][0] = 1000;
  dp[2][0] = 1000;
  // for (int i = 0; i < n; ++i) {
  //   int maxv = max({dp[0][i-1], dp[0][i-1], dp[2][i-1]});
  //   dp[0][i] = maxv;
  //   dp[1][i] =
  // }

  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if(v[i] == v[j]) continue;
      if(v[i] > v[j]) is_high[i] = 1;
      else is_high[i] = -1;
      break;
    }
  }

  ll money = 1000;
  ll kabu = 0;
  for (int i = 0; i < n; ++i) {
    if(is_high[i] == -1){
      kabu += money / v[i];
      money %= v[i];
    }else if(is_high[i] == 1 || i == n-1){
      money += kabu * v[i];
      kabu = 0;
    }
  }

  cout << money << endl;

}
