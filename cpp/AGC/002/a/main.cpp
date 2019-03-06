#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

typedef long long ll;
typedef pair<int, int> p;

int n, m;
vector<int> state;

void init(){
  state = vector<int>(n, -1);
  state[0] = 1;
}

bool give(int from){
  if(state[from] == 1){
    state[from] = 0;
    return true;
  }else if(state[from] >= 2){
    state[from]--;
    return true;
  }else{
    state[from]++;
    return false;
  }
  // if(state == 3)
}

void given(int to, int is_red){
  if(is_red){
    if(state[to] == 0) state[to] = 1;
    else state[to] = abs(state[to]) + 1;
    // else state[to] = 2;
  }else{
    if(state[to] == 1) state[to] = 2;
    else if(state[to] > 1) state[to]++;
    else state[to]--;
  }
}


int main(){
  cin >> n >> m;
  vector<p> v(m);
  init();

  int res = 0;
  for (int i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
    v[i].first--; v[i].second--;
    int from = v[i].first;
    int to = v[i].second;
    bool is_red = give(from);
    // print(state);
    // if(state[from] == 0 && is_red) res--;
    given(to, is_red);
    // print(state);
  }

  for(auto a : state){
    if(a >= 1) res++;
  }
  cout << res << endl;
}
