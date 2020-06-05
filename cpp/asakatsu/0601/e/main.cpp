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
ll n, k;
vector<ll> a, f;

bool check(ll t){
  ll remain = k;
  // cout << t << endl;
  for (int i = 0; i < n; ++i) {
    ll target = t / f[i];
    remain -= max(0ll, a[i] - target);
  }
  // cout << remain << endl;
  return remain >= 0;
}

void res(ll ok){
  cout << ok << endl;
}

int bs(int maxv){
  ll ng = -1, ok = LLONG_MAX / 2;
  while(ok - ng >= 2){
    ll mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  res(ok);
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  a = vector<ll> (n);
  f = vector<ll> (n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> f[i];
  sort(ALL(a));
  sort(RALL(f));
  // print(a);
  // print(f);
  bs(a[n-1]);
}
