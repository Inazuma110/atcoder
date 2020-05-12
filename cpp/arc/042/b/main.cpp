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
  int x, y;
  int n;
  cin >> x >> y >> n;
  vector<p> point(n);
  rep(i, n) cin >> point[i].first >> point[i].second;
  long double res = INT_MAX;

  for (int i = 0; i < n-1; ++i) {
    int x1 = point[i].first;
    int y1 = point[i].second;
    int x2 = point[i+1].first;
    int y2 = point[i+1].second;
    long double s = abs((x1 - x)*(y2 - y) - (x2 - x)*(y1 - y));
    long double h = s / sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    chmin(res, h);
  }

  int x1 = point[0].first;
  int y1 = point[0].second;
  int x2 = point[n-1].first;
  int y2 = point[n-1].second;
  long double s = abs((x1 - x)*(y2 - y) - (x2 - x)*(y1 - y));
  long double h = s / sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
  chmin(res, h);

  cout << setprecision(15);
  cout << res << endl;
}
