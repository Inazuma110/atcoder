#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
using namespace atcoder;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;

struct S{
  ll hp;
};

S op(S a, S b){
  return {a.hp + b.hp};
}

S e(){ return {0};}

struct F{
  ll val;
};

S mapping(F f, S x){
  return {f.val + x.hp};
}

F comp(F a, F b){
  return {a.val + b.val};
}

F id(){ return {0};}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d, a;
  cin >> n >> d >> a;
  vector<p> v(n);
  vector<S> hp(n);
  rep(i, n){
    cin >> v[i].first >> v[i].second;
  }
  sort(ALL(v));
  rep(i, n) hp[i] = {v[i].second};

  vector<ll> doko(n);

  rep(i, n){
    ll l = -1, r = n;
    while(r-l>1){
      ll mid = (l+r)/2;
      if(v[i].first+2*d >= v[mid].first) l = mid;
      else r = mid;
    }
    doko[i] = l;
    // cout << l << ' ' << r << endl;
  }

  lazy_segtree<S, op, e, F, mapping, comp, id> seg(hp);

  ll res = 0;
  rep(i, n){
    ll num = (seg.get(i).hp+a-1) / a;
    num = max(num, 0ll);
    res += num;
    seg.apply(i, doko[i]+1, {-num*a});
  }

  cout << res << endl;
}
