#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>

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

int pcnt(int x){
  return __builtin_popcount(x);
}

int f(int x){
  if(x == 0) return 0;
  return f(x%pcnt(x))+1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int b = 0;
  for (int i = 0; i < n; ++i) {
    if(s[i] == '1') b++;
  }
  vector<int> ans(n);

  ll sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; ++i) {
    sum1 *= 2;
    sum1 %= b + 1;
    if(s[i] == '1') sum1++;
    sum1 %= b + 1;
    if(b-1 <= 0) continue;
    sum2 *= 2;
    sum2 %= b - 1;
    if(s[i] == '1') sum2++;
    sum2 %= b - 1;
  }

  ll now = 1;
  for (int i = n-1; i >= 0; --i) {
    now %= b+1;
    if(s[i] == '0'){
      ll k = (sum1 + now) % (b+1);
      ans[i] = f(k) + 1;
    }
    now *= 2;
    now %= b+1;
  }

  now = 1;
  for (int i = n-1; i >= 0; --i) {
    if(b-1 <= 0) continue;
    now %= b-1;
    if(s[i] == '1'){
      ll k = (sum2 - now + b - 1) % (b-1);
      ans[i] = f(k) + 1;
    }
    now *= 2;
    now %= b-1;
  }

  rep(i, n) cout << ans[i] << endl;

}
