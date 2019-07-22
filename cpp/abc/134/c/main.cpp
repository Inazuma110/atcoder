#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;

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
    data = vector<ll> (seg_tree_size, -1);
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
      data[k] = max(data[k * 2  + 1], data[k * 2 + 2]);
    }
  }


  // [a, b)の最小値を求める
  // kは節点の番号。l, rはその節点が[1, r)に対応づいている
  // (a, b, 0, 0, n)として呼び出す。
  int query(int a, int b, int k, int l, int r){
    // cout << l << " : " << r << endl;
    // cout << a << " : " << b << endl;
    // 交差しなければ
    if(r <= a || b <= l) return -1;
    // [a, b)が[1, r)を完全に含んでいれば、この節点の値
    if(a <= l && r <= b) return data[k];
    // そうでなければ、2つの子の最小値
    else{
      int vl = query(a, b, k*2+1, l, (l+r)/2);
      int vr = query(a, b, k*2+2, (l+r)/2, r);
      // cout << min(vl, vr) << endl;
      return max(vl, vr);
    }
  }

  int query(int a, int b){
    return query(a, b, 0, 0, nums_size);
  }

};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  SegTree st(n, v);
  // print(st.data);

  cout << st.query(1, n) << endl;
  for (int i = 1; i < n-1; i++) {
    cout << max(st.query(0, i), st.query(i+1, n)) << endl;
  }
  cout << st.query(0, n-1) << endl;

}
