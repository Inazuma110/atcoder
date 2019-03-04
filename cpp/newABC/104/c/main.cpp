#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 110110110

typedef long long ll;
typedef pair<int, int> p;

int d, g;
vector<p> v;

vector<p> init(){
  vector<p> tmp(d);
  for (int i = 0; i < d; i++) {
    cin >> tmp[i].first >> tmp[i].second;
  }
  return tmp;
}

int res = INF;

void calc(vector<bool> use){
    int sum_point = 0;
    int sum = 0;
    for (int i = 0; i < d; i++) {
      if(use[i]) {
        sum_point += v[i].first * 100 * (i+1) + v[i].second;
        sum += v[i].first;
      }
    }
    if(sum_point < g){
      for (int i = d-1; i >= 0; i--) {
        if(!use[i]) {
          if(sum_point + v[i].first * 100 * (i+1) < g) break;
          else{
            sum += ceil(double(g - sum_point) / double((i+1) * 100));
            sum_point += ceil(double(g - sum_point) / double((i+1) * 100)) * 100 * (i+1);
          }
          break;
        }
      }
    }
    // cout << sum << endl;
    // cout << sum_point << endl;
    if(sum_point >= g) res = min(res, sum);
}

void dfs(int step, vector<bool> use){
  if(step == d){
    // print(use);
    calc(use);
    return;
  }
  dfs(step+1, use);
  use[step] = true;
  dfs(step+1, use);
}


int main(){
  cin >> d >> g;
  v = init();
  vector<bool> use(d, false);
  dfs(0, use);
  cout << res << endl;
}
