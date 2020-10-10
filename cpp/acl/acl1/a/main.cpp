#include <atcoder/dsu.hpp>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
using namespace atcoder;

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
  cin >> n;
  vector<p> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  map<p, int> d;
  rep(i, n) d[v[i]] = i;
  sort(ALL(v));
  vector<int> tmp(n);
  rep(i, n) tmp[i] = d[v[i]];

  dsu uni(n+10);
  map<int, int> minvs;
  minvs[0] = v[0].second;
  set<int> s = {0};

  for (int i = 1; i < n; ++i) {
    bool is_merged = false;
    minvs[i] = v[i].second;
    int now = v[i].second;
    for(auto root : s){
      if(minvs[root] < now){
        uni.merge(i, root);
        minvs[i] = minvs[root] = min(minvs[i], minvs[root]);
        is_merged = true;
        if(root != uni.leader(root)){
          s.erase(root);
          s.insert(i);
        }
      }
    }
    // cout << "--------------------" << endl;

    if(!is_merged){
      s.insert(i);
    }
  }


  rep(i, n){
    cout << uni.size(i) << endl;
  }


}
