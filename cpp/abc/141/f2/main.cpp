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

void printbs(int size, vector<bitset<100>> vv){
  for (int i = 0; i < size; i++) {
    print(vv[i]);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  vector<bitset<100>> vv(n);
  rep(i, n){
    vv[i] = bitset<100> (v[i]);
  }

  for (int i = 0; i < 100; i++) {
    int odd = 0;
    vector<int> flags(n, false);
    for (int j = 0; j < n; j++) {
      if(vv[j][i] == 1){
        odd++;
        flags[j] = true;
      }
    }
    print(flags);

    ll sum1 = 0, sum2 = 0;
    if(odd % 2 == 1){
      for (int j = 0; j < n; j++) {
        if(flags[j]) sum1 ^= v[j];
        else sum2 ^= v[j];
      }
      cout << sum1 + sum2 << endl;
      return 0;
    }
  }

}
