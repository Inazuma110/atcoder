#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <queue>

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
  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p(a), q(b), r(c);
  rep(i, a) cin >> p[i];
  rep(i, b) cin >> q[i];
  rep(i, c) cin >> r[i];
  sort(RALL(p));
  sort(RALL(q));
  sort(RALL(r));
  priority_queue<pair<int, int>> pq;
  rep(i, a) pq.push({p[i], 1});
  rep(i, b) pq.push({q[i], 2});
  rep(i, c) pq.push({r[i], 3});
  ll sum = 0;
  int n1 = 0, n2 = 0;
  for(int i = 0; i < x+y; i++){
    int c = pq.top().second;
    int v = pq.top().first;
    pq.pop();
    if(c == 1) n1++;
    if(c == 2) n2++;
    if((n1 > x && c == 1) || (c == 2 && n2 > y)){
      i--;
      continue;
    }
    sum += v;
  }

  cout << sum << endl;

}
