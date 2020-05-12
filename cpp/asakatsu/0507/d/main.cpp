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
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];

  int maxv = 0;
  // if(n <= 20){
  //   for (int s = 0; s < n-2; ++s) {
  //     for (int t = 0; t < n-2; ++t) {
  //       for (int u = 0; u < n-2; ++u) {
  //         bool flag = true;
  //         for (int i = s; i < t-1; ++i) {
  //           if(v[i] > v[i+1]){
  //             flag = false;
  //             break;
  //           }
  //         }
  //         for (int i = t; i < u-1; ++i) {
  //           if(v[i] < v[i+1]){
  //             flag = false;
  //             break;
  //           }
  //         }
  //         if(flag){ chmax(maxv, u-s+1); }
  //       }
  //     }
  //   }
  //   cout << maxv << endl;
  //   return 0;
  // }

  maxv = 1;
  for (int s = 0; s < n-1; ++s) {
    int t = s;
    for (; t < n; ++t) {
      if(t == n-1) break;
      if(v[t+1] <= v[t]) break;
    }
    int u = t;
    bool flag = false;
    for (; u < n; ++u) {
      if(u == n-1) break;
      if(v[u+1] >= v[u]) {
        flag = true;
        break;
      }
    }
    chmax(maxv, u-s+1);
    // cout << s << ' ' << t << ' ' << u << endl;
    s = u-1;
  }

  cout << maxv << endl;
}
