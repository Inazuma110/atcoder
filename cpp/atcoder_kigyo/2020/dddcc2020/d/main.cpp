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
  int m;
  cin >> m;
  vector<p> v(m);
  ll keta = 0, sum = 0;
  rep(i, m){
    cin >> v[i].first >> v[i].second;
    keta += v[i].second;
    sum += v[i].first * v[i].second;
  }
  ll res = (keta - 1) + (sum - 1) / 9;
  cout << res << endl;

}
