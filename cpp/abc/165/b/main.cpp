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

long double logn(ll base, ll tv)
{
  return log(tv) / log(base);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x;
  cin >> x;
  ll money = 100;
  for (int i = 1; ; ++i) {
    money = double(money)*1.01;

    if(money >= x) {
      cout << i << endl;
      break;
    }
  }


}
