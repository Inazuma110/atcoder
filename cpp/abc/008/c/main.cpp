#include <bits/stdc++.h>
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
  long double n;
  cin >> n;
  vector<long double> v(n);
  rep(i, n) cin >> v[i];
  long double res = 0;
  rep(i, n){
    long double k = 0;
    rep(j, n) {
      if(int(v[i]) % int(v[j]) == 0) k++;
    }
    res += ((int(k) % 2 != 0) ? ((k + 1.0) / 2 / k) : 0.5);
  }
  cout<<setprecision(15);
  cout << res << endl;
}
