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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, d;
  cin >> n >> d;
  vector<ll> v1(n);
  vector<ll> v2(n);
  rep(i, n) cin>> v1[i] >> v2[i];
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if(v1[i]*v1[i] + v2[i]*v2[i] <= d*d) count++;
  }
  cout << count << endl;

}
