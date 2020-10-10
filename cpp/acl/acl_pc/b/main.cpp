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
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  rep(i, n){
    ll val;
    cin >> val;
    fw.add(i, val);
  }

  rep(i, q){
    ll t, val1, val2;
    cin >> t >> val1 >> val2;
    if(t == 0){
      fw.add(val1, val2);
    }else{
      cout << fw.sum(val1, val2) << endl;
    }
  }

}
