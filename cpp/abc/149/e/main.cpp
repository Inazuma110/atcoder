#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <queue>
#include <vector>

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
ll n, m;

void f(vector<int> v){
  ll res = 0;
  int n = int(v.size());
  priority_queue<int> q;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      q.push(v[i] + v[j]);
    }
  }

  for (int i = 0; i < m; i++) {
    res += q.top();
    q.pop();
  }
  cout << res << endl;

  // while(!q.empty()){
  //   res += q.top();
  //   q.pop();
  //   cout << res << endl;
  // }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  sort(RALL(v));
  // print(v);
  f(v);
}
