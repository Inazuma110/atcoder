#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

vector<ll> uni(100100, -1);

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
ll size(int a)
{
  return -uni[root(a)];
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<p> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
  }

  vector<ll> ans(m, 0);
  ans[m-1] = (n * (n-1)) / 2;

  for (int i = m-1; i >= 1; i--) {
    if(root(v[i].first) != root(v[i].second)){
      ans[i-1] = ans[i] - size(v[i].first) * size(v[i].second);
      connect(v[i].first, v[i].second);
    }
  }

  for(auto a : ans) cout << a << endl;

}
