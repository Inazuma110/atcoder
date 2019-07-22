#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<ll> v(n+1);
  for (ll i = 1; i <= n; i++) {
    cin >> v[i];
  }
  vector<int> b(n+1);

  for (int i = n; i >= 1; i--) {
    int sum = 0;
    for (int j = i+i; j <= n; j += i) {
      sum ^= b[j];
    }
    // cout << sum << endl;
    b[i] = sum^v[i];
  }
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if(b[i]) res.push_back(i);
  }
  // print(b);

  cout << res.size() << endl;
  for(auto a : res){
    cout << a << ' ';
  }
  cout << endl;

}
