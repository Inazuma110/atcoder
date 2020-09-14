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
  ll t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    priority_queue<pair<int, p>> pq;
    int n;
    cin >> n;
    for (int j = 0; j < n; ++j) {
      int k, l, r;
      cin >> k >> l >> r;
      pq.push({j, {l, k}});
      pq.push({j, {r, -k}});
    }


    vector<int> res(n, -1);
    ll count = 0;
    int num = 0;
    vector<int> used(n, false);
    set<int> used2;

    while(!pq.empty()){
      ll val = pq.top().second.first;
      ll p = pq.top().second.second;
      int id = pq.top().first;
      pq.pop();
      if(used[id]) continue;

      if(p > 0){
        int j = s.lower_bound(
        for (int j = p-1; j >= 0; --j) {
          if(res[j] == -1){
            res[j] = val;
            count += val;
            num ++;
            used[id] = true;
            break;
          }
        }
      }else{
        if(-p >= n) continue;
        for (int j = n-1; j >= 0; j--) {
          if(res[j] == -1){
            res[j] = val;
            count += val;
            num ++;
            used[id] = true;
            break;
          }
        }
      }

      if(num == n) break;
    }

    cout << count << endl;
  }
}
