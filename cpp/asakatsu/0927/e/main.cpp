#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
// using namespace atcoder;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
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
  vector<ll> v(n);
  deque<ll> deq;
  rep(i, n){
    cin >> v[i];
    deq.push_back(v[i]);
  }

  ll res = 0;
  while(deq.size() >= 2){
    ll l1 = deq.front();
    deq.pop_front();
    ll l2 = deq.front();
    deq.pop_front();
    ll r1 = deq.back();
    deq.pop_back();
    ll r2 = deq.back();
    deq.pop_back();
    if(l1 + l2 < r1 + r2){
      // cout << l1 << ' ' << l2 << endl;
      ll val = l1 + l2 + 2;
      res += 2*l1 + l2 + 1;
      ll tmp = deq.front();
      deq.pop_front();
      deq.push_front(val+tmp);
      deq.push_back(r2);
      deq.push_back(r1);
    }else{
      // cout << r1 << ' ' << r2 << endl;
      ll val = r1 + r2 + 2;
      res += 2*r1 + r2 + 1;
      ll tmp = deq.back();
      deq.pop_back();
      deq.push_back(val+tmp);
      deq.push_front(l2);
      deq.push_front(l1);
    }
  }

  cout << res << endl;

}
