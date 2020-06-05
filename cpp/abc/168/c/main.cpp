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
  long double a, b, h, m;
  cin >> a >> b >> h >> m;
  long double md = m * 360.0 / 60.0;
  long double hd = (360.0 * h / 12.0) + 360.0 * m / (60.0 * 12.0);
  long double pi = acos(-1);
  long double diffd = abs(md - hd) * pi / 180.0;
  long double res = a*a + b*b - 2*a*b*cos(diffd);
  cout << setprecision(15);
  cout << sqrt(res) << endl;
}
