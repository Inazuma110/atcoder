#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

ll n, a, b;

bool f(ll t, vector<ll> v){
  ll max_attack = 0;
  for (int i = 0; i < n; i++) {
    v[i] -= b * t;
    if(v[i] > 0){
      max_attack += ceil(double(v[i]) / double((a-b)));
    }
  }
  // cout << "attack_num : " << t << endl;
  // cout << "max_attack : " << max_attack << endl;
  // print(v);

  return (max_attack <= t) ? true : false;
}


int main(){
  cin >> n >> a >> b;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int l = -1, r = pow(10, 9) + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if(f(mid, v)) r = mid;
    else l = mid;
  }


  cout << r << endl;

}
