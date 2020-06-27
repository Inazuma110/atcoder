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
vector<int> v;

ll solve(int a){
  ll sum = 0;
  ll res = 0;
  // if(sum == 0){
  //   sum = a*1;
  //   res = a*1;
  // }

  for (int i = 0; i < n; ++i) {
    if((i % 2 == a && (sum + v[i]) < 0) || (i % 2 == 0) && sum +v[i] > 0){
      sum += v[i];
      continue;
    }
    ll remain = 0;
    if(i % 2 == a){
      remain = -1 - v[i] - sum;
    }else{
      remain = 1 - v[i] - sum;
    }
    // cout << remain << endl;
    res += abs(remain);
    sum += remain + v[i];
    // cout << sum << endl;
    // cout << "===" << endl;
  }
  // cout << "===" << endl;
  return res;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  v = vector<int> (n);
  rep(i, n) cin >> v[i];
  ll res = min(solve(1), solve(0));

  cout << res << endl;
  // cout << solve(0) << endl;
}
