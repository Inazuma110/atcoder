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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i, n) cin >> v[i];

  vector<int> res(n);
  for (int i = 0; i < min(k, 100); ++i) {
    vector<int> tmp(n+10);
    for (int j = 0; j < n; ++j) {
      tmp[max(j+1-v[j], 0)]++;
      tmp[min(j+1+v[j]+1, n+3)]--;
    }
    for (int j = 0; j < n; ++j) {
      tmp[j+1] += tmp[j];
      v[j] = tmp[j+1];
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << v[i] << ' ';
  }
  cout << endl;
}
