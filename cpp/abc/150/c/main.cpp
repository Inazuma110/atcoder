#include <algorithm>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
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

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  string ps = "", qs = "";
  rep(i, n) cin >> q[i];

  rep(i, n) ps += to_string(p[i]);
  rep(i, n) qs += to_string(q[i]);


  vector<int> v(n);
  rep(i, n) v[i] = i + 1;

  vector<string> res;
  do {
    string tmp  = "";
    for (int i = 0; i < n; i++) {
      tmp += to_string(v[i]);
    }
    res.push_back(tmp);
  } while (next_permutation(ALL(v)));

  int a, b;
  for (int i = 0; i < int(res.size()); i++) {
    if(ps == res[i]) a = i;
    if(qs == res[i]) b = i;
  }
  cout << abs(a-b) << endl;
}
