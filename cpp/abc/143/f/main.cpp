#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
//
// using boost::multiprecision::cpp_int;
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
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> mp;
  rep(i, n){
    cin >> v[i];
    mp[v[i]]++;
  }
  priority_queue<int> pq1;
  priority_queue<int> pq2;
  for(auto a : mp){
    pq1.push(a.second);
    pq2.push(a.second);
  }

  for (int i = 1; i <= n; i++) {
    pq2 = pq1;
    ll res = 0;
    while(pq2.size() > 1) {
      int a = pq2.top();
      pq2.pop();
      int b = pq2.top();
      pq2.pop();
      res += b / i;
      if(a % i != 0) pq2.push(a % i);
      if(b % i != 0) pq2.push(b % i);
    }
    cout << res << endl;
  }

}
