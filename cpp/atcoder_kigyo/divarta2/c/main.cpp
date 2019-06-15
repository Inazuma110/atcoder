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
  vector<int> minous;
  vector<int> plus;
  ll res = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    res += abs(v[i]);
    if(v[i] == 0) {
      minous.push_back(0);
      plus.push_back(0);
    }

    if(v[i] < 0) minous.push_back(v[i]);
    else if(v[i] > 0) plus.push_back(v[i]);
  }

  sort(ALL(v));
  sort(ALL(minous));
  sort(ALL(plus));

  if(n == 2){
    if(v[0] > v[1]){
      cout << v[0] << ' ' << v[1] << endl;
      cout << v[0]-v[1] << endl;
    }else{
      cout << v[1] << ' ' << v[0] << endl;
      cout << v[1]-v[0] << endl;
    }
    return 0;
  }


  if(int(plus.size()) == n){
    ll sum2 = v[0];
    ll maxv2 = v[n-1];
    for (int i = 1; i < n-1; i++){
      sum2 -= v[i];
    }
    maxv2 -= sum2;
    cout << maxv2 << endl;


    ll sum = v[0];
    ll maxv = v[n-1];
    for (int i = 1; i < n-1; i++){
      cout << sum <<' ' << v[i] << endl;
      sum -= v[i];
    }
    cout << maxv << ' ' << sum << endl;
    return 0;
  }else if(int(minous.size()) == n){
    ll sum2 = v[n-1];
    ll maxv2 = v[0];
    for (int i = n-2; i >= 1; i--) {
      sum2 -= v[i];
    }
    sum2 -= maxv2;
    cout << sum2 << endl;

    ll sum = v[n-1];
    ll maxv = v[0];
    for (int i = n-2; i >= 1; i--) {
      cout << sum << ' ' << v[i] << endl;
      sum -= v[i];
    }
    cout << sum << ' ' << maxv << endl;
    return 0;
  }

  int index = -1;
  cout << res << endl;
  for (int i = 0; i < n; i++) {
    if(v[i] >= 0){
      index = i;
      break;
    }
  }


  ll sum = v[index-1];
  for (int i = index; i < n-1; i++) {
    cout << sum << ' ' << v[i] << endl;
    sum -= v[i];
  }
  cout << v[n-1] << ' ' << sum << endl;
  sum = v[n-1] - sum;
  for (int i = 0; i < index-1; i++) {
    cout << sum << ' ' << v[i] << endl;
    sum -= v[i];
  }
}
