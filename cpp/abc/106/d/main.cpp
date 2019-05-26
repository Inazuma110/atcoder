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
  int n, m, q;
  cin >> n >> m >> q;
  vector<p> lr(m);
  for (int i = 0; i < m; i++) {
    cin >> lr[i].first >> lr[i].second;
  }
  vector<p> query(q);
  for (int i = 0; i < q; i++) {
    cin >> query[i].first >> query[i].second;
  }
  vector<ll> sum(m+1);


}
