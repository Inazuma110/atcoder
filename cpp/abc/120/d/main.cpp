#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<ll, ll> p;

vector<ll> uni(100100, -1);

// 頂点aの所属するグループを調べる。
ll root(ll a)
{
  // uni[a]が負の値なら親はa自身
  if (uni[a] < 0) return a;
  // 正の値であれば、親ルートを調べ戻り値で根に直接つなぐ。
  else {
    uni[a] = root(uni[a]);
    return uni[a];
    // return uni[a] = root(uni[a]);
  }
}

// 頂点aとbをつなぐ、もともと同じグループの場合falseを返す。
bool connect(ll a, ll b)
{
  a = root(a);
  b = root(b);
  if (a == b) return false;

  // aを大きなグループにしたいので、逆であれば入れ替える。
  if (uni[a] > uni[b])
  {
    ll hoge = a;
    a = b;
    b = hoge;
  }

  //aとbを結合し、bをaの親とする。
  uni[a] += uni[b];
  uni[b] = a;
  return true;
}

//  頂点a, bが同じグループか
bool isConnect(ll a, ll b)
{
  return root(a) == root(b);
}

// 頂点aを含むグループの頂点数を調べる
ll size(ll a)
{
  return -uni[root(a)];
}

int main(){
  ll n, m;
  cin >> n >> m;
  vector<p> v(m);
  for (ll i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
  }

  vector<ll> ans(m, 0);
  ans[m-1] = (n * (n-1)) / 2;

  for (ll i = m-1; i >= 1; i--) {
    if(root(v[i].first) != root(v[i].second)){
      ans[i-1] = ans[i] - size(v[i].first) * size(v[i].second);
      connect(v[i].first, v[i].second);
    }
    else ans[i-1] = ans[i];
  }

  for(auto a : ans) cout << a << endl;

}
