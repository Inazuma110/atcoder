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
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n+m, INT_MAX), b(n+m, INT_MAX);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  vector<ll> sum1(n+1), sum2(m+1);
  rep(i, n) sum1[i+1] = sum1[i] + a[i];
  rep(i, m) sum2[i+1] = sum2[i] + b[i];
  ll maxv = 0;
  for (ll i = 0; i < n+1; ++i) {
    ll count = i;
    ll rem = k - sum1[count];
    if(rem < 0) continue;
    ll ind = upper_bound(ALL(sum2), rem) - sum2.begin();
    ind--;
    chmax(maxv, ind+count);
  }
  // print(sum1);
  // print(sum2);
  cout << maxv << endl;
}
