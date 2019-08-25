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
  ll sum = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      sum += i * j;
    }
  }
  sum -= n;

  for (int i = 1; i <= sum && i < 10; i++) {
    if(sum % i == 0 && sum / i < 10){
      cout << i << " x " << sum / i << endl;
    }
  }
}
