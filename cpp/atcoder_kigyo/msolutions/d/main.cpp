#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;

struct Tree {
  ll node_num;
  ll edge_num;
  ll diameter = -1;
  ll far_index = -1;
  vector<vector<ll>> to;
  vector<bool> visited;
  vector<int> depth;
  vector<int> point;

  Tree(ll nn) : node_num(nn){
    edge_num = node_num - 1;
    to = vector<vector<ll>> (node_num);
    visited = vector<bool> (node_num, false);
    depth = vector<int> (node_num);
    point = vector<int> (node_num);
  }


  pair<ll, ll> get_far(ll from, ll d){
    visited[from] = true;
    for(auto a : to[from]){
      if(!visited[a]){
        get_far(a, d+1);
      }
    }
    if(diameter < d){
      diameter = d;
      far_index = from;
    }
    return {far_index, diameter};
  }

  ll get_diameter(ll from){
    pair<ll, ll> i_and_d = get_far(0, 0);
    init();
    diameter = get_far(i_and_d.first, 0).second;
    init();
    return diameter;
  }

  void init(){
    visited = vector<bool> (node_num, false);
  }

  int now = 0;
  int set_depth(int from, int d){
    visited[from] = true;
    for(auto a : to[from]){
      if(!visited[a]) set_depth(a, d+1);
    }
    depth[from] = point[now];
    now++;
    return depth[from] = d;
  }
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  Tree t(n);
  ll res = 0;
  vector<p> bridge(n-1);
  for (ll i = 0; i < n-1; i++) {
    ll from, to;
    cin >> from >> to;
    from--;to--;
    t.to[from].push_back(to);
    t.to[to].push_back(from);
    bridge[i] = {from, to};
  }
  vector<int> point(n);
  for (int i = 0; i < n; i++) {
    cin >> point[i];
  }
  sort(RALL(point));
  t.point = point;
  t.set_depth(0, 0);
  t.init();
  vector<p> tmp(n);
  for (int i = 0; i < n; i++) {
    tmp[i] = {t.depth[i], i};
  }
  sort(ALL(tmp));
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int index = tmp[i].second;
    mp[index] = t.point[i];
  }

  for(auto a : bridge){
    res += min(mp[a.first], mp[a.second]);
  }

  cout << res << endl;
  for(auto a : mp){
    cout << a.second << " ";
  }
  cout << endl;
}
