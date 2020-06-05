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
  vector<set<char>> v(n);
  vector<string> memo(n);

  rep(i, n){
    string s;
    cin >> s;
    memo[i] = s;
    for(auto c : s) v[i].insert(c);
  }

  string res = "";
  for (int i = 0; i < n/2; ++i) {
    for(auto c : v[i]){
      if(v[n-1-i].count(c) == 1){
        res += c;
        break;
      }
    }
  }

  string res2 = res;
  reverse(ALL(res2));

  if(n == 1) cout << memo[0][0] << endl;
  else if(res.size() < n/2) cout << -1 << endl;
  else if(n % 2 == 0) cout << res << res2 << endl;
  else cout << res << memo[n/2][0] << res2 << endl;

}
