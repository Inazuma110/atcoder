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

int n;
ll res = 0;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<vector<pair<bool, bool>>> v(n, vector<pair<bool, bool>>(n, {false, false}));
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < n; j++) {
      if(int(tmp[j] - '0') == 1) v[i][j].first = true;
      else v[i][j].first = false;
    }
  }
  vector<set<int>> s(n);
  s[0].insert(0);

  queue<int> q;
  q.push(0);

  while(!q.empty()){
    int now = q.front();
    q.pop();

    for (int i = 0; i < n; i++) {
      if(!v[now][i].second){
        v[now][i].second = true;
        v[i][now].second = true;
        bool next = v[now][i].first;

        if(v[i][now].first != next){
          cout << -1 << endl;
          return 0;
        }

        if(next){
          for(auto a : s[now]){
            s[i].insert(a+1);
            s[i].insert(a-1);
          }
          q.push(next);
        }
      }
    }
  }
  vector<int> res(n, INT_MAX);
  res[0] = 0;
  for (int i = 1; i < n; i++) {
    bool flag = false;
    for(auto a : s[i]){
      for (int j = 0; j < i; j++) {
        if(res[j] == a) flag = true;
      }
      if(flag) continue;
      else res[i] = a;
    }
    if(res[i] == INT_MAX) res[i] = *s[i].begin();
  }
  print(res);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(v[i][j].first){
        if(abs(res[i] - res[j]) != 1){
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  set<int> tmp(ALL(res));
  cout << tmp.size() << endl;
}
