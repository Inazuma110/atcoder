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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<p> v(n);
  set<int> sx;
  set<int> sy;
  map<int, int> mpx;
  map<int, int> mpy;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = {x, y};
    sx.insert(x);
    sy.insert(y);
    mpx[x]++;
    mpy[y]++;
  }
  if(n <= 2){
    cout << 0 << endl;
    return 0;
  }
  ll res = 0;

  for (int i = 0; i < n; i++) {
    int x = v[i].first;
    int y = v[i].second;
    if(mpx[x] >= 2 && mpy[y] >= 2){
      res += max(mpx[x], mpy[y]) - min(mpx[x], mpy[y]);
    }
  }


  cout << (int(sx.size()) * int(sy.size())) - n << endl;

}
