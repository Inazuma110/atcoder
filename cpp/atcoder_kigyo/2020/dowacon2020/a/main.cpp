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

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<string, int>> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  string x;
  cin >> x;

  ll res = 0;
  bool flag = false;
  rep(i, n){
    if(flag) res += v[i].second;
    if(x == v[i].first) flag = true;
  }
  cout << res << endl;
}
