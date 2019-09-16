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
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  vector<int> idx(n);
  rep(i, n) idx[v[i]] = i;

  set<int> s;
  ll res = 0;
  for (int i = n-1; i >= 0; i--) {
    int index = idx[i];
    ll c = 0;
    s.insert(i);
    vector<int> l(2, -1);
    vector<int> r(2, n);
    auto it = s.find(i);
    rep(j, 2){
      if(it == s.begin()) break;
      --it;
      l[j] = *it;
    }
    it = s.find(i);
    rep(j, 2){
      if(it == s.end()) break;
      ++it;
      r[j] = *it;
    }
    vector<int> ls(2);
    ls[0] = index-l[0];
    ls[1] = l[0]-l[1];
    res += c * (i+1);
  }

}
