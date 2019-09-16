#include <bits/stdc++.h>

using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  sort(ALL(v));
  vector<int> visited(n);

  ll res = 0;
  for (int i = 0; i < n; i++) {
    if(visited[i]) continue;
    visited[i] = true;
    res++;
    for (int j = i+1; j < n; j++) {
      if(v[j] % v[i] == 0){
        visited[j] = true;
      }
    }
  }

  cout << res << endl;
}
