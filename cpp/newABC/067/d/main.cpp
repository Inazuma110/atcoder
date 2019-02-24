#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

int n;

vector<vector<int>> tree;

vector<vector<int>> tree_init(){
  vector<vector<int>> tree(n, vector<int>());
  for (int i = 0; i < n-1; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    tmp1--; tmp2--;
    tree[tmp1].push_back(tmp2);
    tree[tmp2].push_back(tmp1);
  }
  return tree;
}

vector<int> distance1;
vector<int> distance2;

void dist_init(){
  for (int i = 0; i < n; i++) {
    distance1.push_back(0);
    distance2.push_back(0);
  }
}

map<int, bool> visited;


void dfs(int from, int distance){
  visited[from] = true;
  for(auto a : tree[from]){
    if(visited[a]) continue;
    cout << from << endl;
    print(tree[from]);
    distance1[from] = distance;
    dfs(a, distance + 1);
  }
}

int main(){
  cin >> n;
  tree = tree_init();
  dist_init();

  dfs(0, 0);
  print(distance1);



}
