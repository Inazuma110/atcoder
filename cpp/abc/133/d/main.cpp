#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  vector<ll> m(n);
  ll count = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if(i % 2 == 0) count += v[i];
    else count -= v[i];
  }
  m[0] = count;
  for (int i = 0; i < n-1; i++) {
    m[i+1] = (v[i]*2 - m[i]);
  }

  for(auto a : m){
    cout << a << ' ';
  }
  cout << endl;
}
