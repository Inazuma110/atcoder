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
  string s;
  ll k;
  cin >> s >> k;
  ll n = ll(s.size());
  vector<int> v(1, 1);
  for (int i = 1; i < n; i++) {
    if(s[i] == s[i-1]) v[v.size()-1]++;
    else v.push_back(1);
  }
  if(v.size() == 1) cout << (n * k) / 2 << endl;
  else{
    ll res = 0;
    for(auto a : v){
      res += a / 2;
    }
    if(s[0] == s[n-1]){
      v[0] += v[v.size()-1];
      v.pop_back();
    }
    for(auto a : v){
      res += (a / 2) * (k-1);
    }
    cout << res << endl;
  }

}
