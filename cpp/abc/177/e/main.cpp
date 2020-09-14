#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

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

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  else return gcd(b, a % b);
  // return (b == 0) ? a : gcd(b, a % b);
}

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  return (ret);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto start = clock();
  ll n;
  cin >> n;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];

  vector<ll> ana(1000010);
  bool is_pairwise = true;

  bool yaba = n == 1000000;
  for (ll i = 0; i < n; ++i) {
    if(v[i] == 1) continue;
    auto end = clock();
    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    if(time >= 1800.0 && yaba){
      yaba = true;
      break;
    }
    auto yakusu = divisor(v[i]);
    for(auto a : yakusu){
      if(a == 1) continue;
      if(ana[a] == 1) {
        is_pairwise = false;
        break;
      }
      ana[a] = 1;
    }
  }
  if(is_pairwise){
    cout << "pairwise coprime" << endl;
    exit(0);
  }

  ll res = v[0];

  for (ll i = 0; i < n; ++i) {
    res = gcd(res, v[i]);
  }
  if(res == 1){
    cout << "setwise coprime" << endl;
    exit(0);
  }
  cout << "not coprime" << endl;
}
