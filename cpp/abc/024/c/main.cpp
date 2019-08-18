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
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d, k;
  cin >> n >> d >> k;
  vector<p> lr(d);
  vector<p> st(k);
  for (int i = 0; i < d; i++) {
    cin >> lr[i].first >> lr[i].second;
  }
  for (int i = 0; i < k; i++) {
    cin >> st[i].first >> st[i].second;
  }

  for(auto minzoku : st){
    int from = minzoku.first;
    int to = minzoku.second;
    int count = 0;
    for(auto day : lr){
      int l = day.first;
      int r = day.second;
      count++;
      if(l <= from && from <= r){
        if(l <= to && to <= r) {
          from = to;
          cout << count << endl;
          break;
        }
        from = (abs(to - l) < abs(to - r)) ? l : r;
      }
      // cout << from << endl;
    }
    // cout << "====" << endl;
  }
}
