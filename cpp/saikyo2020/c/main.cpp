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
      data[k] = min(data[k * 2  + 1], data[k * 2 + 2]);
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
      return min(vl, vr);
    }
  }

  int query(int a, int b){
    return query(a, b, 0, 0, nums_size);
  }

};

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
      return min(vl, vr);
    }
  }

  int query(int a, int b){
    return query(a, b, 0, 0, nums_size);
  }

};

struct Graph {
  vector<vector<p>> cost;
  vector<bool> visited;
  vector<int> min_cost;
  int node_num, edge_num;

  Graph(int nn, int en) : node_num(nn), edge_num(en){
    min_cost = vector<int> (node_num, INT_MAX);
    cost = vector<vector<p>> (node_num, vector<p>());
  }


  void dijkstra(int start){
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, start});
    min_cost[start] = 0;

    while(!pq.empty()) {
      int now_cost = pq.top().first;
      int now = pq.top().second;
      pq.pop();
      if(min_cost[now] < now_cost) continue;

      for(auto e : cost[now]){
        if(min_cost[e.first] > now_cost + e.second){
          min_cost[e.first] = now_cost + e.second;
          pq.push({min_cost[e.first], e.first});
        }
      }
    }
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<p, int> mp;
  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    from--; to--;
    if(mp.count({from, to}) == 0){
      mp[{from, to}] = cost;
      mp[{to, from}] = cost;
    }else{
      mp[{from, to}] = min(cost, mp[{from, to}]);
      mp[{to, from}] = min(cost, mp[{from, to}]);
    }
  }

  vector<int> size(n+1);

  vector<ll> o(n, INT_MAX / 2);
  SegTree st(n, o);

  for(auto info : mp){
    int from = info.first.first;
    int to = info.first.second;
    int cost = info.second;
    size[from]++;
    size[to+1]--;
    st.update(from, to);
  }

  for (int i = 1; i < n+1; i++) {
    size[i] += size[i-1];
  }
  int en = 0;
  for (int i = 0; i < n+1; i++) {
    if(size[i] >= 1) en++;
  }


  Graph g(n, en);
  for(auto info : mp){
    int from = info.first.first;
    int to = info.first.second;
    int cost = info.second;
    g.cost[from].push_back({to, cost});
    g.cost[to].push_back({from, cost});
  }
  g.dijkstra(0);

  print(g.min_cost);
  if(g.min_cost[n-1] == INT_MAX) cout << -1 << endl;
  else cout << g.min_cost[n-1] << endl;

}
