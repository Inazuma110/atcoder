#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <iterator>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime MOD
  mint inv() const { return pow(MOD-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint dp[1000010][2][2];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  mint n;
  cin >> n.x;

  for (int i = 0; i < 1000010; ++i) {
    for (int j = 0; j < 2; ++j) {
      dp[i][j][0] = 0;
      dp[i][j][1] = 0;
    }
  }
  dp[1][0][0] = 8;
  dp[1][1][0] = 1;
  dp[1][0][1] = 1;
  dp[1][1][1] = 0;

  for (int i = 2; i < 1000010; ++i) {
    dp[i][0][0] = dp[i-1][0][0] * 8;
    dp[i][1][1] = dp[i-1][0][1] + dp[i-1][1][0] + dp[i-1][1][1] * 10;
    dp[i][0][1] = dp[i-1][0][0] + dp[i-1][0][1] * 9;
    dp[i][1][0] = dp[i-1][0][0] + dp[i-1][0][1] * 9;
  }

  cout << dp[n.x][1][1].x << endl;

  // rep(i, 10){
  //   rep(j, 2){
  //     cout << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
  //   }
  // }

}
