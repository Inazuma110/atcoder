#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
//
// using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  vector<p> v(m);
  ll l = -1, r = INT_MAX;
  rep(i, m){
    cin >> v[i].first >> v[i].second;
    l = max(l, v[i].first);
    r = min(r, v[i].second);
  }
  cout << max(0ll, min(r, n) - l + 1) << endl;
}
