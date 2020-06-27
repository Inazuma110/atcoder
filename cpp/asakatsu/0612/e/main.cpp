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
  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m), d(m);
  // vector<pair<p, int>> v(m);
  // rep(i, n) cin >> v[i].first.second >> v[i].first.first >> v[i].second;
  vector<vector<p>> v(n);
  UnionFind uni;
  rep(i, m){
    int l, r, d;
    cin >> l >> r >> d;
    l--;r--;
    v[l].push_back({r, d});
    v[r].push_back({l, -d});
    uni.connect(l, r);
  }

  set<int> roots;
  for (int i = 0; i < n; ++i) {
    roots.insert(uni.root(i));
  }

  vector<bool> visited(n);
  vector<int> dist(n, -1);
  for(auto r : roots){
    visited[r] = true;
    queue<int> q;
    q.push(r);
    dist[r] = 0;
    while(!q.empty()){
      int from = q.front();
      q.pop();
      visited[from] = true;
      for(auto a : v[from]){
        int to = a.first;
        int d = a.second;
        if(visited[to]) continue;
        visited[to] = true;
        dist[to] = dist[from] + d;
        q.push(to);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for(auto a : v[i]){
      int to = a.first;
      int d = a.second;
      if(dist[i] + d != dist[to]){
        cout << "No" << endl;
        exit(0);
      }
    }
  }
  cout << "Yes" << endl;

}
