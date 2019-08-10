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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> v;
  int count = 1;
  for (int i = 1; i < int(s.size()); i++) {
    if(s[i-1] == s[i]){
      count++;
    }else{
      v.push_back(count);
      count = 1;
    }
  }
  v.push_back(count);
  vector<int> res;


  for (int i = 0; i < int(v.size())-1; i+=2) {
    rep(j, v[i]-1) res.push_back(0);
    int l = v[i];
    int r = v[i+1];
    int big = max(l, r);
    if((l + r) % 2 == 0){
      res.push_back((l + r)/2);
      res.push_back((l + r)/2);
    }else if(l < r){
      if((big - 1) % 2 == 0){
        res.push_back((l + r) / 2);
        res.push_back((l + r) / 2 + 1);
      }else{
        res.push_back((l + r) / 2 + 1);
        res.push_back((l + r) / 2);
      }
    }else{
      if((big - 1) % 2 == 0){
        res.push_back((l + r) / 2 + 1);
        res.push_back((l + r) / 2);
      }else{
        res.push_back((l + r) / 2);
        res.push_back((l + r) / 2 + 1);
      }
    }
    rep(j, v[i+1]-1) res.push_back(0);
  }

  rep(i, res.size()) cout << res[i] << ' ';
  cout << endl;


}
