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
  int n, q;
  cin >> n >> q;
  vector<p> v(n);
  vector<multiset<int>>s(200005);
  multiset<int> maxs;

  auto get_max = [&](int i){
    if(s[i].size() == 0) return INT_MAX;
    return *(s[i].rbegin());
  };
  auto del_yochien = [&](int i){
    int x = get_max(i);
    if(x == -1) return;
    maxs.erase(maxs.find(x));
  };
  auto add_yochien = [&](int i){
    int x = get_max(i);
    if(x == -1) return;
    maxs.insert(x);
  };
  auto add_enji = [&](int i, int x) {
    del_yochien(i);
    s[i].insert(x);
    add_yochien(i);
  };
  auto del_enji = [&](int i, int x){
    del_yochien(i);
    s[i].erase(s[i].find(x));
    add_yochien(i);
  };

  rep(i, n){
    cin >> v[i].first >> v[i].second;
    add_enji(v[i].second, v[i].first);
    // mp[v[i].second].insert({i, v[i].first});

  }



  // rep(i, q){
  //   int c, d;
  //   cin >> c >> d;
  //   c--;
  //   del_enji(v[c].second, v[c].first);
  //   v[c].second = d;
  //   add_enji(v[c].second, v[c].first);
  //   int ans = *maxs.begin();
  //   cout << ans << endl;
  // }
}
