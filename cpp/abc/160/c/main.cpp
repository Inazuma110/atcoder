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
  int k, n;
  cin >> k >> n;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];

  // ll res = 0;
  // ll index = -1;
  ll maxd = k-v[n-1]+v[0];
  for (int i = 0; i < n-1; ++i) {
    maxd = max(maxd, v[i+1]-v[i]);
    // if(v[i+1] - v[i] > maxd){
    //   maxd = v[i+1] - v[i];
    //   // index = i;
    // }
  }
  // cout << maxd << endl;
  cout << k - maxd << endl;
}
