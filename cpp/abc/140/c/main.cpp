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

void f(){

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n-1);
  rep(i, n-1) cin >> v[i];
  ll res = 0;
  vector<int> a(n);
  a[0] = v[0];
  a[n-1] = v[n-2];
  for (int i = 1; i < n-1; i++) {
    a[i] = min(v[i], v[i-1]);
  }
  rep(i, n) res += a[i];

  cout << res << endl;
}

