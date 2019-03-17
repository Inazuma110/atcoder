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
  ll n, l;
  cin >> n >> l;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll maxv = -1;
  ll maxv_index = -1;
  for (int i = 1; i < n; i++) {
    if(maxv < v[i] + v[i-1]){
      maxv_index = i;
      maxv = v[i] + v[i-1];
    }
  }

  if(maxv < l){
    cout << "Impossible" << endl;
  }else{
    cout << "Possible" << endl;
    for (int i = 0; i < n-1; i++) {
      if(i+1 == maxv_index) break;
      cout << i+1 << endl;
    }
    for (int i = n-2; i+1 > maxv_index; i--) {
      cout << i+1 << endl;
    }
    cout << maxv_index << endl;
  }
}
