#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;

struct UnionFind {
  // 要素に対応する値は自分の根。根は要素数の-1倍したものを代入する。
  // 根ならそのグループの要素数(負)が、子であれば親の番号が入る。初期値-1。
  vector<int> uni;
  UnionFind(){
    uni = vector<int>(300100, -1);
  }

  // 頂点aの所属するグループを調べる。
  int root(int a)
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
  bool connect(int a, int b)
  {
    a = root(a);
    b = root(b);
    if (a == b) return false;

    // aを大きなグループにしたいので、逆であれば入れ替える。
    if (uni[a] > uni[b])
    {
      int hoge = a;
      a = b;
      b = hoge;
    }

    //aとbを結合し、bをaの親とする。
    uni[a] += uni[b];
    uni[b] = a;
    return true;
  }

  //  頂点a, bが同じグループか
  bool isConnect(int a, int b)
  {
    return root(a) == root(b);
  }

  // 頂点aを含むグループの頂点数を調べる
  int size(int a)
  {
    return -uni[root(a)];
  }

};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i, n){
    cin >> v[i];
    v[i]--;
  }
  UnionFind uni;

  int s = 0;
  int now = 0;
  int next = 0;
  vector<int> path(n, INT_MAX);
  path[0] = 0;
  rep(i, n+100){
    if(i == k){
      cout << next+1 << endl;
      return 0;
    }
    if(uni.isConnect(0, v[next]) && i != 0) {
      s = uni.size(0);
      k -= path[v[next]];
      s = s - path[v[next]];
      break;
    }
    now = next;
    next = v[next];
    path[next] = i+1;
    uni.connect(0, next);
  }

  if(s == 0){
    s = 1;
  }

  ll num = k % s;

  int res = v[next];
  rep(i, num){
    res = v[res];
  }
  cout << res + 1 << endl;
}
