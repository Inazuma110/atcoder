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
  ll res = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  res += v[0] / 2;
  v[0] %= 2;

  for (int i = 1; i < n; i++) {
    if(v[i] >= 1 && v[i-1] % 2 == 1){
      res++;
      v[i]--;
    }
    res += v[i] / 2;
    v[i] %= 2;
    // print(v);
  }

  cout << res << endl;
}
