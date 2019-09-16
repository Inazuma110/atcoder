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
  ll period = n / 5;
  period %= 6;
  ll r = n % 5;
  string res = "";
  for(int i = period + 1; i <= 6; i++){
    res += to_string(i);
  }
  for (int i = 1; i <= period; i++) {
    res += to_string(i);
  }

  for (int i = 0; i < r; i++) {
    swap(res[i], res[i+1]);
  }
  cout << res << endl;

}
