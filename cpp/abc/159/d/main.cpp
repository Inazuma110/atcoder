#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

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
  ll n;
  cin >> n;
  vector<ll> v(n);
  map<ll, ll> mp;
  ll sum = 0;
  rep(i, n) {
    cin >> v[i];
    mp[v[i]]++;
  }
  for(auto a : mp){
    sum += ((a.second - 1)*a.second) / 2;
  }

  rep(i, n){
    ll k = v[i];
    sum -= ((mp[k]-1)*mp[k]) / 2;
    sum += ((mp[k]-1)*(mp[k]-2)) / 2;
    cout << sum << endl;
    sum -= ((mp[k]-1)*(mp[k]-2)) / 2;
    sum += ((mp[k]-1)*mp[k]) / 2;
  }
}
