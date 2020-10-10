#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include<atcoder/all>

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

ll f(ll a, ll b){
  return max(a, b);
}
ll e(){return 0;}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, q;
  cin >> n >> q;
  vector<ll> v(n);
  rep(i, n) {
    cin >> v[i];
  }

  segtree<ll, f, e> seg(v);
  rep(i, q){
    int t, x, v;
    cin >> t >> x >> v;
    if(t == 1){
      seg.set(x-1, v);
    }
    if(t == 2){
      cout << seg.prod(x-1, v) << endl;
    }else{

    }
    }
  }

}
