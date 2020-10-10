#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
// using namespace atcoder;

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
  int n;
  cin >> n;
  vector<pair<int, p>> v(n);
  map<int, vector<ll>> mp;

  rep(i, n){
    cin >> v[i].first >> v[i].second.first;
    v[i].second.first--;
    v[i].second.second = i;
    if(mp[v[i].first].size() == 0) mp[v[i].first] = vector<ll> (3);
    mp[v[i].first][v[i].second.first]++;
  }
  sort(ALL(v));
  ll sum = 0;
  ll count = 0;
  // win draw lose
  vector<vector<int>> res(n, vector<int>(3));

  for (int i = 0; i < n; ++i) {
    int rate = v[i].first;
    int hand = v[i].second.first;
    int id = v[i].second.second;
    res[id][0] = sum + mp[rate][(hand+1)%3];
    res[id][1] = mp[rate][hand] - 1;
    res[id][2] = n-1 - res[id][0] - res[id][1];
    count++;
    if(i < n-1 && v[i].first != v[i+1].first) sum += count, count=0;
  }

  rep(i, n){
    cout << res[i][0] << ' ' << res[i][2] << ' ' << res[i][1] << endl;
  }

}
