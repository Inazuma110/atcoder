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

struct SegTree {
  int seg_tree_size = 1;
  int nums_size;
  vector<ll> data;

  SegTree(int origin_size, vector<ll> a) {
    // 簡単のため数列の要素数が2のべき乗と考える
    while(seg_tree_size < origin_size) seg_tree_size *= 2;
    nums_size = seg_tree_size;
    seg_tree_size = seg_tree_size * 2 - 1;

    // 2分木の要素数は2*要素数-1
    // n + n/2 + n/4 + n/8 + ... 1 = 2*n-1
    data = vector<ll> (seg_tree_size, pow(2, 31));
    for (int i = 0; i < origin_size; i++) {
      update(i, a[i]);
    }
  }

  // k番目の値をxに変更
  void update(int k, int a){
    // 葉のノードの番号
    k += (seg_tree_size - nums_size);
    data[k] = a;

    // 登りながら更新
    while(k > 0) {
      k = (k-1) / 2;
      data[k] = (data[k * 2  + 1] + data[k * 2 + 2]);
    }
  }


  // [a, b)の最小値を求める
  // kは節点の番号。l, rはその節点が[1, r)に対応づいている
  // (a, b, 0, 0, n)として呼び出す。
  int query(int a, int b, int k, int l, int r){
    // cout << l << " : " << r << endl;
    // cout << a << " : " << b << endl;
    // 交差しなければ
    if(r <= a || b <= l) return INT_MAX;
    // [a, b)が[1, r)を完全に含んでいれば、この節点の値
    if(a <= l && r <= b) return data[k];
    // そうでなければ、2つの子の最小値
    else{
      int vl = query(a, b, k*2+1, l, (l+r)/2);
      int vr = query(a, b, k*2+2, (l+r)/2, r);
      // cout << min(vl, vr) << endl;
      return (vl + vr);
    }
  }

  int query(int a, int b){
    return query(a, b, 0, 0, nums_size);
  }

};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s, q;
  cin >> n >> s >> q;
  vector<ll> v(n, 1);
  SegTree st(n, v);
  for (int i = 0; i < q; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    if(t == 1){
      st.update(l, r);
    }else{
      cout << st.query(l, r) << endl;
    }
  }

}
