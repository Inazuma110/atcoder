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

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<p> v(n), tmp(n);
  priority_queue<p> q;
  map<int, ll> mp;
  rep(i, n){
    cin >> v[i].first;
    v[i].second = i;
    mp[i] = v[i].first;
    q.push(v[i]);
  }

  for (int i = 0; i < k; i++) {
    ll val = q.top().first;
    ll index = q.top().second;
    q.pop();
    if(index == 0){
      val = mp[index+1];
    }else if(index == n-1){
      val = mp[index-1];
    }else{
      if(mp[index+1] < mp[index-1]){
        val = mp[index+1];
      }else{
        val = mp[index-1];
      }
    }
    mp[index] = val;
    q.push({val, index});
  }

  // print(mp);
  ll res = 0;
  while(true){
    bool flag = true;
    bool all_zero = true;
    for (int i = 0; i < n; i++) {
      if(i == 0 && mp[1] == 0){
        res += mp[i];
        mp[i] = 0;
        continue;
      }else if(i == n-1 && mp[n-2] == 0){
        res += mp[i];
        mp[i] = 0;
        continue;
      }else if(mp[i-1] == 0 && mp[i+1] == 0){
        res += mp[i];
        continue;
      }
      if(mp[i] >= 1){
        if(flag) res++;
        mp[i]--;
        flag = false;
        all_zero = false;
      }
      else {
        flag = true;
        continue;
      }
    }
    // cout << res << endl;
    if(all_zero) break;
  }
  cout << res << endl;

}
