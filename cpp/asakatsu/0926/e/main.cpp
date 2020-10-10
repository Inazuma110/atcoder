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

struct obj{
  int rank, id, order;
};

bool operator<(const obj& a, const obj& b){
  if(a.rank == b.rank){
    if(a.order == b.order) return a.id > b.id;
    return a.order > b.order;
  }
  return a.rank > b.rank;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> v(n, vector<int>(k));
  rep(i, n){
    rep(rank, k){
      cin >> v[i][rank];
    }
  }

  set<int> s;
  rep(i, n){
    int count = k/n;
    if(i <= k % n) count++;
    rep(j, k){
    }
  }
}
