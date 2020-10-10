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

using mint = modint998244353;

struct S{
  mint sum, len;
};

struct F{
  mint b, c;
};

S op(S s_l, S s_r){
  return {s_l.sum + s_r.sum, s_l.len+s_r.len};
}

S e(){ return {0, 0};}

S mapping(F f, S s){
  return {f.b * s.sum + f.c * s.len, s.len};
}

F comp(F f, F g){
  return {f.b*g.b, f.b*g.c+f.c};
}

F id(){
  return {1, 0};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, q;
  cin >> n >> q;
  vector<mint> a(n);
  lazy_segtree<S, op, e, F, mapping, comp, id> seg(n);
  rep(i, n){
    ll val;
    cin >> val;
    a[i] = val;
    seg.set(i, {a[i], 1});
  }

  while(q--){
    int t;
    cin >> t;
    if(t==0){
      ll l, r, b, c;
      cin >> l >> r >> b >> c;
      seg.apply(l, r, {(mint)b, (mint)c});
    }else{
      ll l, r;
      cin >> l >> r;
      cout << seg.prod(l, r).sum.val() << endl;
    }
  }
}
