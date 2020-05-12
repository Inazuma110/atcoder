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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;

int n;
vector<vector<long double>> dp;
vector<long double> v;

void dfs(){
  for (int i = 1; i <= n; ++i) {
    for(int count = 0; count < i; count++){
      // cout << i << ' ' << count << endl;
      dp[i][count+1] += dp[i-1][count] * v[i-1];
      dp[i][count] += dp[i-1][count] * (1-v[i-1]);
      // print(dp);
    }
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  v = vector<long double>(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  dp = vector<vector<long double>> (n+3, vector<long double>(n+3, 0));
  dp[0][0] = 1;
  dp[0][1] = 0;
  dfs();
  long double res = 0;
  for(int count = n/2+1; count <= n; count++){
    res += dp[n][count];
  }
  cout << setprecision(15);
  cout << res << endl;

}
