#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
// using namespace atcoder;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
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
  string s;
  cin >> n >> s;
  map<char, vector<ll>> sums;
  rep(i, n){
    if(sums[s[i]].size() == 0) sums[s[i]] = vector<ll> (n+1);
    sums[s[i]][i+1]++;
  }
  char ss[] = {'A', 'G', 'C', 'T'};
  rep(i, 4){
    if(sums[ss[i]].size() == 0) sums[ss[i]] = vector<ll> (n+1);
    for (int j = 1; j < n+1; ++j) {
      sums[ss[i]][j] += sums[ss[i]][j-1];
    }
    // print(sum);
  }

  ll res = 0;
  for (int i = 1; i < n+1; ++i) {
    for (int j = i+1; j < n+1; ++j) {
      ll a = sums['A'][j] - sums['A'][i-1];
      ll g = sums['G'][j] - sums['G'][i-1];
      ll c = sums['C'][j] - sums['C'][i-1];
      ll t = sums['T'][j] - sums['T'][i-1];

      if(a == t && c == g) res++;
    }
  }

  cout << res << endl;

}
