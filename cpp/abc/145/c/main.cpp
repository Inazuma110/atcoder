#include <algorithm>
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

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<long double, long double>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(ALL(v));

  long double res = 0;
  do{
    long double fx = v[0].first;
    long double fy = v[0].second;
    for (int i = 1; i < n; i++) {
      long double nx = v[i].first;
      long double ny = v[i].second;
      res += sqrt((nx-fx)*(nx-fx) + (ny-fy)*(ny-fy));
      fx = v[i].first;
      fy = v[i].second;
    }
  }while(next_permutation(ALL(v)));
  for (long double i = 1; i <= n; i++) {
    res /= i;
  }
  cout<<setprecision(15);
  cout << res << endl;
}
