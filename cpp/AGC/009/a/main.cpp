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
  vector<p> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  ll res = 0;
  for (int i = n-1; i >= 0; i--) {
    ll now = v[i].first;
    ll target = v[i].second;
    ll tmp = (now + res) % target;
    if(tmp == 0) continue;
    res += target - tmp;
  }
  cout << res << endl;
}
