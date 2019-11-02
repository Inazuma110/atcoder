#include <bits/stdc++.h>
#include <cmath>
// #include <boost/multiprecision/cpp_int.hpp>
//
// using boost::multiprecision::cpp_int;
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
  long double a, b, x;
  cin >> a >> b >> x;
  cout<<setprecision(15);
  if(x/a >= a * b / 2.0){
    long double h = ((a*b - x/a)*2) / a;
    cout << atan2(h, a) * 180 / M_PI << endl;
  }else{
    long double w = 2 * (x/a) / b;
    cout << atan2(b, w) * 180 / M_PI << endl;
  }
}
