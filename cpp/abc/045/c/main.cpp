#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;
ll s;
vector<string> v;
ll res = 0;

void dfs(int step, vector<int> op){
  if(step == int(op.size())){
    ll count = 0;
    string now = v[0];
    for (int i = 0; i < int(op.size()); i++) {
      if(op[i] == 0){
        count += stoll(now);
        now = "";
      }
      now += v[i+1];
      // cout << now << endl;
    }
    res += count + stoll(now);
    return;
  }
  dfs(step+1, op);
  op[step] = 1;
  dfs(step+1, op);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  v = vector<string> (to_string(s).size());
  for (int i = 0; i < int(to_string(s).size()); i++) {
    v[i] = to_string(s)[i];
  }
  // print(v);
  vector<int> op(v.size() - 1);

  dfs(0, op);

  cout << res << endl;

}
