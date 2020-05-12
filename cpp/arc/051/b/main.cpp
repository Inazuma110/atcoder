#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

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

int counter = 0;
int gcd(int a, int b) {
    if (b == 0) return a;
    counter++;
    return gcd(b, a%b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll k;
  cin >> k;
  vector<int> used;
  ll a = 1, b = 1;
  bool flag = true;
  for (int i = 0; i < k; ++i) {
    int n = int(used.size());
    for(int j = (n >= 1) ? used[n-1] : 2; ; j++){
      bool is_div = false;
      for(auto a : used){
        if(j % a == 0){
          is_div = true;
          break;
        }
      }
      if(!is_div){
        cout << j << endl;
        if(flag) a *= j;
        else b *= j;
        used.push_back(j);
        flag = !flag;
        break;
      }
    }
  }
  cout << a << ' ' << b << endl;

  gcd(a, b);
  cout << counter << endl;
}
