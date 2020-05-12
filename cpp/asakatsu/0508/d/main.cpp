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

int n;
// iは嘘か本当か
vector<vector<p>> v;
int res = 0;

int check(vector<int> state){
  int count = 0;
  int n = int(state.size());

  for(int s = 0; s < n; s++){
    if(state[s] == 0) continue;
    bool flag = false;
    for(auto a : v[s]){
      int man = a.first;
      int tf = a.second;
      if(tf != state[man]) return 0;
    }
    if(!flag) count++;
  }
  chmax(res, count);
  // cout << count << endl;
  return 1;
}

void dfs(int step, vector<int> state){
  if(step == n){
    // print(state);
    check(state);
    return;
  }
  dfs(step+1, state);
  state[step] = 1;
  dfs(step+1, state);
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  v = vector<vector<p>> (n, vector<p>());
  rep(i, n){
    int a = 0;
    cin >> a;
    rep(j, a){
      int tmp1, tmp2;
      cin >> tmp1 >> tmp2;
      tmp1--;
      v[i].push_back({tmp1, tmp2});
    }
  }
  dfs(0, vector<int> (n));
  cout << res << endl;

}
