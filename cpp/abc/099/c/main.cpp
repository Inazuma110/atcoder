#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<int> dp(n+100);
  dp[1] = 1;

  for (int i = 1; i < n+100; ++i) {
    dp[i] = dp[i-1] + 1;
    int tmp = 1;
    while(i - pow(6, tmp) >= 0){
      dp[i] = min(dp[i], dp[i - int(pow(6, tmp))] + 1);
      tmp++;
    }
    tmp = 1;
    while(i - pow(9, tmp) >= 0){
      dp[i] = min(dp[i], dp[i - int(pow(9, tmp))] + 1);
      tmp++;
    }
  }

  cout << dp[n] << endl;
}
