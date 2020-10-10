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

long long comb(int n, int r) {
  if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
  long long ans = 1;

  for(int i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }

  return ans;
}

int main(){
  int n, p;
  cin >> n >> p;
  vector<ll> v(n);
  int kisu = 0;
  int gusu = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if(v[i] % 2 == 1) kisu++;
    else gusu++;
  }

  ll res = 0;
  ll tmp = pow(2, gusu);

  if(p == 0){
    for (int i = 0; i <= kisu; i+=2) {
      res += tmp * comb(kisu, i);
    }
  }else{
    for (int i = 1; i <= kisu; i+=2) {
      res += tmp * comb(kisu, i);
    }
  }

  cout << res << endl;



}
