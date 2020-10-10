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
int n;

bool check(vector<p> v){
  rep(i, n) if(v[i].second < v[i].first) return false;
  for (int i = 1; i < n; ++i) {
    if(v[i].first < v[i-1].first) return false;
    if(v[i].second < v[i-1].second) return false;
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<p> v(n);
  vector<int> used(2*n+1);
  priority_queue<p> pq;
  bool flag = false;
  rep(i, n){
    cin >> v[i].first >> v[i].second;
  }

}
