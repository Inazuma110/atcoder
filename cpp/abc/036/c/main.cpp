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
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  set<int> s(ALL(v));
  vector<int> tmp(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    int index = lower_bound(ALL(tmp), v[i]) - tmp.begin();
    cout << index << endl;
  }

}
