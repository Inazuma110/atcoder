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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string res = s;
  string u;
  for(int i = 0; i < n; i++){
    int x = i;
    for(int j = i+1; j < n; j++){
      cout << res << endl;
      if(res[x] > res[j]){
        u = res;
        swap(u[i], u[j]);
        int cnt = 0;
        rep(l, n) if(s[l] != u[l]) cnt++;
        if(cnt <= k) x = j;
      }
    }
    swap(res[i], res[x]);
  }
  cout << res << endl;
}
