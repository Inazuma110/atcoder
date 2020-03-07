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
    uni = vector<int>(100100, -1);
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<p> friends(m), block(k);
  vector<int> dir(n);
  map<int, vector<int>> mp;
  rep(i, m){
    cin >> friends[i].first >> friends[i].second;
    friends[i].first--; friends[i].second--;
    dir[friends[i].first]++;
    dir[friends[i].second]++;
  }
  rep(i, k){
    cin >> block[i].first >> block[i].second;
    block[i].first--; block[i].second--;
    mp[block[i].first].push_back(block[i].second);
    mp[block[i].second].push_back(block[i].first);
  }

  UnionFind uf;
  UnionFind uf2;

  rep(i, m){
    uf.connect(friends[i].first, friends[i].second);
  }

  rep(i, k){
    uf2.connect(block[i].first, block[i].second);
  }

  rep(i, n){
    int count = 0;
    for(auto a : mp[i]){
      // cout << a << endl;
      count += (uf2.isConnect(i, a) && uf.isConnect(i, a));
    }
    // cout << count << endl;
    cout << max(0, uf.size(i)-1 - dir[i] - count) << ' ';
  }
  cout << endl;
}
