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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  priority_queue<pair<ll, p>> pq;
  vector<bool> row(n), col(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ll cost = abs(i-j) * v[i];
      pq.push({cost, {i, j}});
    }
  }

  int count = 0;
  ll res = 0;
  while(!pq.empty()){
    ll cost = pq.top().first;
    ll from = pq.top().second.first;
    ll to = pq.top().second.second;
    pq.pop();
    if(row[from] || col[to]) continue;
    cout << cost << endl;
    cout << from << ' ' << to << endl;
    row[from] = true;
    col[to] = true;
    res += cost;
    count++;
    if(count == n) break;
  }
  cout << res <<endl;
}
