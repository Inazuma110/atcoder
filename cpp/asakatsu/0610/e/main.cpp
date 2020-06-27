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
  long double p;
  cin >> p;

  auto f = [&](long double x){ return p/pow(2.0, x/1.5)+x; };

  long double low = 0;
  long double high = 1e9;

  for (int i = 0; i < 10000; ++i) {
    long double h1 = (low*2+high) / 3;
    long double h2 = (low+2*high) / 3;

    if(f(h1) > f(h2)) low = h1;
    else high = h2;
  }

  cout << setprecision(15);
  cout << f(low) << endl;
}
