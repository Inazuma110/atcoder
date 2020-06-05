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

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  else return gcd(b, a % b);
  // return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  ll g = gcd(a, b);
  return a / g * b;
}

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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<p> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  int zero = 0;
  map<p, ll> mp;
  ll katal_zero = 0;
  ll katar_zero = 0;
  rep(i, n){
    if(v[i].first == 0 && v[i].second == 0) {
      zero++;
      continue;
    }
    if(v[i].second < v[i].first){
      v[i].first *= -1;
      v[i].second *= -1;
    }
    ll tmp = gcd(v[i].first, v[i].second);
    v[i].first = v[i].first / tmp;
    v[i].second = v[i].second / tmp;
    if(v[i].first == 0ll) katal_zero++;
    if(v[i].second == 0ll) katar_zero++;
    mp[v[i]] += 1;
  }

  mint res = 1;
  map<p, bool> visited;

  // cout << katal_zero << ' ' << katar_zero << endl;
  // print(mp);

  for(auto a : mp){
    ll x = a.first.first;
    ll y = a.first.second;
    if(a.second == 0ll || visited[{x, y}]) continue;
    // int num = mp[{y, -x}].x;
    if(x == 0 || y == 0) {
      visited[{1, 0}] = true;
      visited[{0, 1}] = true;
    }else{
      visited[{x, y}] = true;
      visited[{y, -x}] = true;
    }
    mint tmp = 1;
    tmp += mint(2).pow(mp[{x, y}])-1;
    tmp += mint(2).pow(mp[{y, -x}])-1;

    res *= tmp;
  }

  res += zero;
  res -= 1;

  cout << res << endl;
}
