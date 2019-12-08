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
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  ll res = 0;

  vector<ll> count(100);

  for (int i = 0; i < n; i++) {
    // while(tmp < v[i]){
    //   tmp *= 2;
    //   ci++;
    // }
    int index = 0;
    while(v[i] > 0){
      if(v[i] % 2 == 1) count[index]++;
      v[i] /= 2;
      index++;
    }
  }

  for (int i = 0; i < 100; i++) {
    res += (count[i] * (n-count[i]) % MOD) * (ll(pow(2, i)) % MOD);
    res %= MOD;
  }
  cout << res << endl;

}
