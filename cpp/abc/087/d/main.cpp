#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

const int MOD = 1000000007;

struct Info {
  map<int, int> cost;
  // vector<int> to;
  // vector<int> cost;
  int index = MOD;
  bool visited = false;
};


int main(){
  int n, m;
  cin >> n >> m;
  vector<Info> v(n);
  for (int i = 0; i < m; i++) {
    int l, r, d;
    cin >> l >> r >> d;
    l--;r--;
    v[l].cost[r] = d;
    v[r].cost[l] = -d;
  }

  int now = 0;
  int before = 0;
  v[0].index = 0;
  while(true) {
    if(!v[now].visited && v[now].index == MOD) {
      index = 0;
      v[now].visited = true;
    }
    v[i].index = v[now].index + v[now].cost[i];
    if(v[i].visited && v[i].index)
  }




}
