#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
using namespace atcoder;

// #if __has_include("print.hpp")
//   #include "print.hpp"
// #endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 998244353

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;

using mint = modint998244353;
struct S{
  mint x, w;
  S(mint x=0, mint w=1): x(x), w(w){}
};

S op(S a, S b){
  return S(a.x*b.w + b.x, a.w*b.w);
}

S e() {return S();}

S mapping(int f, S a){
  if(f == 0) return a;
  return S((a.w-1)/9 * f, a.w);
}

int comp(int f, int g){
  if(f == 0) return g;
  return f;
}

int id(){ return 0;}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, q;
  cin >> n >> q;

  lazy_segtree<S, op, e, int, mapping, comp, id> t(n);

  rep(i, n) t.set(i, S(1, 10));
  while(q--){
    int l, r, d;
    cin >> l >> r >> d;
    l--;
    t.apply(l, r, d);
    // S ans = t.prod(0, n);
    // cout << ans.x.val() << endl;
    // printf("%lld\n", (ll)t.all_prod().x.val());
    cout << t.all_prod().x.val() << endl;
  }
}
