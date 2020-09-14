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
  ll h, w, m;
  cin >> h >> w >> m;
  map<ll, ll> mp1;
  map<ll, ll> mp2;
  map<p, ll> mp;
  rep(i, m) {
    ll hi, wi;
    cin >> hi >> wi;
    mp1[hi]++;
    mp2[wi]++;
    mp[{hi, wi}] = 1;
  }

  auto y = max_element(mp1.begin(), mp1.end(),
      [](const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
      return p1.second < p2.second;
      });
  ll res = y->second;

  for(auto a : mp){
    if(a.first.first == y->first){
      mp2[a.first.second]--;
    }
  }

  auto x = max_element(mp2.begin(), mp2.end(),
      [](const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
      return p1.second < p2.second;
      });

  res += x->second;
  cout << res << endl;
}
