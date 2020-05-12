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
  int x, y;
  cin >> x >> y;
  ll res = 0;
  map<int, int> mp;
  mp[3] = 100000;
  mp[2] = 200000;
  mp[1] = 300000;
  res = mp[x] + mp[y];
  if(x == 1 && y == 1) res += 400000;
  cout << res << endl;
}
