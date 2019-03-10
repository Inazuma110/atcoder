#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

typedef long long ll;
typedef pair<int, int> p;


int main(){
  int n;
  cin >> n;
  vector<ll> v(3*n);
  for (int i = 0; i < 3*n; i++) {
    cin >> v[i];
  }
  sort(all(v));
  ll res = 0;
  ll count = 0;
  for (int i = 3*n-2; count != n; i-=2) {
    count++;
    res += v[i];
    // cout << res << endl;
  }
  cout << res << endl;
}
