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
  ll n;
  cin >> n;
  ll res = 0;
  int d = 0;
  for (ll i = n; i > 0; i /= 2) {
    d++;
  }

  ll x = 1;

  while(x <= n){
    if(d % 2 == 1){
      if(res % 2 == 0) x = 2 * x + 1;
      else x *= 2;
    }else{
      if(res % 2 == 1) x = 2 * x + 1;
      else x *= 2;
    }
    res++;
  }

  if(res % 2 == 1){
    cout << "Aoki" << endl;
  }else{
    cout << "Takahashi" << endl;
  }

}
