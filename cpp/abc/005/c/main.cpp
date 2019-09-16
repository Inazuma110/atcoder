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
  int t, n;
  cin >> t >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int m;
  cin >> m;
  vector<int> b(m);
  rep(i, m) cin >> b[i];
  sort(ALL(a));
  sort(ALL(b));
  vector<bool> used(n, false);

  rep(i, m){
    bool flag = false;
    rep(j, n){
      if(!used[j]){
        if(a[j] + t >= b[i] && b[i] >= a[j]){
          used[j] = true;
          flag = true;
          break;
        }
      }
    }
    if(!flag){
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;

}
