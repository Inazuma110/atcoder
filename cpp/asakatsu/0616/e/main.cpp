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

vector<int> t(24, -1);

int check(int h){
  int maxv1 = -1;
  int maxv2 = -1;

  for (int i = 0; i < 24; ++i) {
    if(t[i] == -1) continue;
    if (t[h] == -1) {
      maxv1 = abs(i - h);
    }
    if (h != 0 && t[24 - h] == -1) {
      maxv2 = abs(24-h-i);
    }
  }

  if(maxv1 == -1 && maxv2 == -1){
    cout << 0 << endl;
    exit(0);
  }

  if(maxv1 > maxv2){
    t[h] = 1;
  }else{
    t[24-h] = 1;
  }

  return 0;
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  t[0] = 1;
  rep(i, n) cin >> v[i];

  for (int i = 0; i < n; ++i) {
    check(v[i]);
  }

  int minv = INT_MAX;
  if(t[23] == 1 && t[0] == 1) minv = 1;
  int count = 1;
  for (int i = 1; i < 24; ++i) {
    // cout << count << endl;
    if(t[i] == -1) count++;
    else{
      chmin(minv, count);
      count = 1;
      // cout << "===" << endl;
    }
  }

  cout << minv << endl;

}
