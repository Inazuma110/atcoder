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
  ll n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  vector<ll> a(n);
  vector<ll> b(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
    a[i] = i * n;
    b[i] = (n - i) * n;
  }

  for (int i = 0; i < n; i++) {
    a[v[i].first-1] += (i+1);
  }


  for (int i = 0; i < n-1; i++) {
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;

  for (int i = 0; i < n-1; i++) {
    cout << b[i] << " ";
  }
  cout << b[n-1] << endl;
}
