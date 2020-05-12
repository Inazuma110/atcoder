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


bool is_num(char s){
  return s >= '0' && s <= '9';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  map<char, int> mp;
  UnionFind uni;
  bool flag = false;
  rep(i, n){
    if(!is_num(s1[i]) && !is_num(s2[i])) uni.connect(int(s1[i]), int(s2[i]));
    else if(is_num(s1[i]) && is_num(s2[i]) && s1[i] != s2[i]) flag = true;
    else if(is_num(s1[i]) && is_num(s2[i])) continue;
    // else mp[s2[i]] = s1[i] - '0'; mp[s1[i]] = s2[i] - '0';
    else if(is_num(s1[i])) uni.connect(int(s2[i]), 0);
    else if(is_num(s2[i])) uni.connect(int(s1[i]), 0);

    if(!is_num(s1[i]) && !is_num(s2[i]) && i == 0) uni.connect(int(s1[i]), 1);
  }
  if(flag) {
    cout << 0 << endl;
    return 0;
  }

  ll res1 = 1;
  reverse(ALL(s1));

  rep(i, n){
    if(is_num(s1[i])) continue;
    if(!uni.isConnect(int(s1[i]), 0) && uni.isConnect(int(s1[i]), 1))
      res1 *= 9;
    else if(!uni.isConnect(int(s1[i]), 0))
      res1 *= 10;
    uni.connect(s1[i], 0);
  }

  cout << res1 << endl;
}
