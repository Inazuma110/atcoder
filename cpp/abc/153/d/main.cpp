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
  ll h;
  cin >> h;
  ll res = 0;
  ll tmp = 0;
  while(true){
    if(h >= 1){
      res += pow(2, tmp);
      tmp++;
      h /= 2;
    }else{
      break;
    }
  }

  cout << res << endl;


}
