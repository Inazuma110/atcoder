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
  vector<int> v(n);
  vector<int> d(n);
  ll sum = 0;
  ll tmp = 0;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
    tmp += i+1;
  }

  if(sum % tmp != 0){
    cout << "NO" << endl;
    return 0;
  }
  ll k = sum / tmp;

  for (int i = 0; i < n-1; i++) {
    d[i] = v[i+1] - v[i];
  }
  d[n-1] = v[0] - v[n-1];

  for (int i = 0; i < n; i++) {
    if(d[i] > k || (k - d[i]) % n != 0){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
