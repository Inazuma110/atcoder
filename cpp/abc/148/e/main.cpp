#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

// typedef long long ll;
typedef cpp_int ll;
typedef pair<ll, ll> p;
// ll res = 0;

vector<ll> dp(100, -1);

ll f(ll n){
  // if(dp[n] != -1) return dp[n];
  // if(n < 2) return dp[n] = 1;
  // else return dp[n] = n * f(n-2);
  if(n < 2) return 1;
  else return n * f(n-2);
}

ll g1(ll n, int p){
  if(n == 0) return 0;
  return n / p + g1(n/p, p);
}

ll g2(ll n, int p){
  if(n % 2 == 1){
    return g1(n, p) - g2(n-1, p);
  }
  ll res = g1(n/2, p);
  if(p == 2) res += n / 2;
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  if(n % 2 == 1) cout << 0 << endl;
  else{
    cout << g2(n, 5) << endl;
  }
}
