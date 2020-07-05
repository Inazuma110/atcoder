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
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  vector<p> abss(n);
  int zeros = 0;
  vector<mint> minous, plus;
  rep(i, n){
    cin >> v[i];
    abss[i].first = abs(v[i]);
    abss[i].second = v[i] < 0 ? 1 : 0;
    if(v[i] == 0) zeros++;
  }
  priority_queue<ll> pq;

  sort(ALL(v));
  sort(RALL(abss));
  rep(i, n){
    if(v[i] < 0){
      minous.push_back(v[i]);
      pq.push(v[i]);
    }
    else if(v[i] > 0)plus.push_back(v[i]);
  }

  mint res = 1;
  int count = 1;
  for (int i = 0; i < k; ++i) {
    if(abss[i].second == 1){
      ll val1 = pq.top();
      pq.pop();
      ll val2 = 0;
      if(!pq.empty()){
        val2 = pq.top();
        pq.pop();
      }

    }
    else{
    }
  }

}
