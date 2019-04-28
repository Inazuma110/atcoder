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

ll sum(vector<ll> v){
  ll count = 0;
  for(auto a : v){
    count += abs(a);
  }
  return count;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<ll> v(n);
  ll count = 0;
  bool zero = false;
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
    if(v[i] == 0) zero = true;
    if(v[i] < 0){
      count++;
    }
  }
  if(count % 2 == 1 && zero) count++;
  if(count % 2 == 0){
    cout << sum(v) << endl;
    return 0;
  }

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = abs(v[i]);
  }
  ll res = sum(v);
  ll minv = *min_element(ALL(a));

  res -= minv * 2;
  cout << res << endl;


}
