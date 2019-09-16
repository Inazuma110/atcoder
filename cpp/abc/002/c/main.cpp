#include <bits/stdc++.h>
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
  long double x0, y0, x1, y1, x2, y2;
  cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
  vector<long double> ab = {x1-x0, y1-y0};
  vector<long double> ac = {x2-x0, y2-y0};

  // long double abs = sqrt(ab[0] * ab[0] + ab[1] * ab[1]);
  // long double acs = sqrt(ac[0] * ac[0] + ac[1] * ac[1]);
  //
  // long double dot = ab[0] * ac[0] - ab[1] * ac[1];
  // long double cos = dot / (abs * acs);
  // long double sin = sqrt(1 - (cos * cos));

  long double s = abs(ab[0] * ac[1] - ab[1] * ac[0]) / 2.0;


  cout<<setprecision(15);
  cout << s << endl;

}
