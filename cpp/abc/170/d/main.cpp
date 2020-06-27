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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  sort(ALL(v));
  int res = 0;
  vector<int> memo(1000005);
  for (int i = 0; i < n; ++i) {
    if(memo[v[i]] != 0){
      memo[v[i]] = 2;
      continue;
    }
    for (int j = 0; j < 1000005; j += v[i]) {
      memo[j]++;
    }
  }

  for (int i = 0; i < n; ++i) {
    if(memo[v[i]] == 1) res++;
  }
  cout << res <<endl;
}
