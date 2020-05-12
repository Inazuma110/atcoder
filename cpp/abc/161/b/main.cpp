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
  double m, n;
  cin >> n >> m;
  vector<double> v(n);
  rep(i, n) cin >> v[i];
  int count = 0;
  double sum = 0;
  rep(i, n){
    sum += v[i];
  }

  rep(i, n){
    if(v[i] >= sum / (4.0*m)) count++;
  }
  // cout << count << endl;

  if(count >= m) cout << "Yes" << endl;
  else cout << "No" << endl;

}
