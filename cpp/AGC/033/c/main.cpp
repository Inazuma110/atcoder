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

struct Node{
  vector<int> to;
  int coin = 1;
  bool visited = false;
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<p> edge(n);
  vector<Node> v(n);

  for (int i = 0; i < n; i++) {
    cin >> edge[i].first >> edge[i].second;
    edge[i].first--;
    edge[i].second--;
    v[edge[i].first].to.push_back(edge[i].second);
    v[edge[i].second].to.push_back(edge[i].first);
  }

  int now = 0;
  while(true){
    if(v[now].to.size() % 2 == 1){
      v[now].coin = 0;
    }
  }



}
