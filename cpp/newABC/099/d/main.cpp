#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;
int n, c;

vector<vector<int>> cost;
vector<vector<int>> field;


vector<vector<int>> cost_init(){
  vector<vector<int>> cost(c, vector<int>(c, 0));
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < c; j++) {
      cin >> cost[i][j];
    }
  }
  return cost;
}

vector<vector<int>> field_init(){
  vector<vector<int>> field(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> field[i][j];
      field[i][j]--;
    }
  }
  return field;
}


vector<int> dfs1(){
  vector<int> cost_set(c, 0);
  for (int k = 0; k < c; k++) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int index = (i + j) % 3;
        if(index == 0){
          int now_color = field[i][j];
          sum += cost[now_color][k];
        }
      }
    }
    cost_set[k] = sum;
  }
  return cost_set;
}

vector<int> dfs2(){
  vector<int> cost_set(c, 0);
  for (int k = 0; k < c; k++) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int index = (i + j) % 3;
        if(index == 1){
          int now_color = field[i][j];
          sum += cost[now_color][k];
        }
      }
    }
    cost_set[k] = sum;
  }
  return cost_set;
}

vector<int> dfs3(){
  vector<int> cost_set(c, 0);
  for (int k = 0; k < c; k++) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int index = (i + j) % 3;
        if(index == 2){
          int now_color = field[i][j];
          sum += cost[now_color][k];
        }
      }
    }
    cost_set[k] = sum;
  }
  return cost_set;
}

int main(){
  cin >> n >> c;
  cost = cost_init();
  field = field_init();
  vector<int> cost_set1 = dfs1();
  vector<int> cost_set2 = dfs2();
  vector<int> cost_set3 = dfs3();

  // print(cost_set1);
  // print(cost_set2);
  // print(cost_set3);

  int res = INT_MAX;
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < c; j++) {
      for (int k = 0; k < c; k++) {
        if(i == j || j == k || i == k) continue;
        res = min(res, cost_set1[i] + cost_set2[j] + cost_set3[k]);
      }
    }
  }
  cout << res << endl;
}
