#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<ll, ll> p;
ll n, a, b, c;
vector<ll> v;
ll res = INT_MAX;

void v_init(){
  for (ll i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
}

void calc(vector<int> tmp){
  int tmpa = 0;
  int tmpb = 0;
  int tmpc = 0;
  ll mp = 0;
  for(int i = 0; i < int(tmp.size()); i++){
    if(tmp[i] == 1) {
      if(tmpa != 0) mp += 10;
      tmpa += v[i];
    }
    if(tmp[i] == 2) {
      if(tmpb != 0) mp += 10;
      tmpb += v[i];
    }
    if(tmp[i] == 3) {
      if(tmpc != 0) mp += 10;
      tmpc += v[i];
    }
  }
  if(tmpa == 0 || tmpb == 0 || tmpc == 0) return;
  mp += abs(tmpa - a);
  mp += abs(tmpb - b);
  mp += abs(tmpc - c);

  res = min(res, mp);
}

void dfs(int which, vector<int> tmp, int step){
  tmp.push_back(which);
  if(step == n-1) {
    calc(tmp);
    return;
  }
  dfs(0, tmp, step+1);
  dfs(1, tmp, step+1);
  dfs(2, tmp, step+1);
  dfs(3, tmp, step+1);

}


int main(){
  cin >> n >> a >> b >> c;
  v_init();
  vector<int> tmp;
  for (int i = 0; i < 4; i++) {
    dfs(i, tmp,  0);
  }


  cout << res << endl;
}
