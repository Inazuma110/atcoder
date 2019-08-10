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
  int n, m;
  cin >> n >> m;
  vector<p> v(n);
  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    // cin >> v[i].second >> v[i].first;
  }
  ll res = 0;
  sort(ALL(v));
  int now = 0;

  for (int i = 1; i <= m; i++) {
    while(now < n && v[now].first <= i){
      q.push(v[now].second);
      now++;
    }
    if(q.size() == 0) continue;
    int tmp = q.top();
    q.pop();
    // cout << now << endl;
    // cout << tmp << endl;
    res += tmp;
  }

  cout << res << endl;

}
