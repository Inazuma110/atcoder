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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> v(h);
  for (int i = 0; i < h; ++i) {
    cin >> v[i];
  }

  ll res = 0;
  for (int i = 0; i < (1 << h); ++i) {
    for (int j = 0; j < (1 << w); ++j) {

      ll count = 0;
      for (int k = 0; k < h; ++k) {
        for (int l= 0; l < w; ++l) {
          if(!(i & (1 << k))) continue;
          if(!(j & (1 << l))) continue;
          if(v[k][l] == '#') count++;
        }
      }

      if(count == k) res++;
    }
  }

  cout << res << endl;
}
