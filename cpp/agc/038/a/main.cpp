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
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  rep(i, h) {
    rep(j, w) {
      if(i < b && j < a) cout << 0;
      else if(i >= b && j >= a) cout << 0;
      else cout << 1;
    }

    cout << endl;
  }
}
