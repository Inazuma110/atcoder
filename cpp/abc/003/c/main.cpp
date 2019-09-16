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
  int n, k;
  cin >> n >> k;
  vector<long double> v(n);
  rep(i, n) cin >> v[i];
  sort(ALL(v));
  long double rate = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if(k - count >= n - i){
      rate += v[i];
      rate /= 2.0;
    }
  }
  cout<<setprecision(15);
  cout << rate << endl;
}
