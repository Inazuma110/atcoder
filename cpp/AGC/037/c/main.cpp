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
  vector<ll> a(n);
  vector<p> b(n);
  rep(i, n) cin >> a[i];
  rep(i, n){
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(RALL(b));
  ll res = 0;

  for(auto x : b){
    ll mokuteki = x.first;
    ll index = x.second;
    ll diff = -1;
    if(index == 0) diff = a[(index + 1) % n] + a[n-1];
    else diff = a[(index + 1) % n] + a[(index - 1) % n];

    if(mokuteki >= a[index] && (mokuteki - a[index]) % diff == 0){
      res += (mokuteki - a[index]) / diff;
      a[index] = mokuteki;
    }else{
      res = -1;
      break;
    }
  }
  cout << res << endl;
}


