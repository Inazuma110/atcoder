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

char f(char a, char b){
  if(a > b) swap(a, b);
  if(a == 'G' && b == 'R') return 'B';
  if(a == 'B' && b == 'G') return 'R';
  if(a == 'B' && b == 'R') return 'G';
  return '@';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vector<int> r, g, b;
  rep(i, n){
    if(s[i] == 'R') r.push_back(i);
    if(s[i] == 'G') g.push_back(i);
    if(s[i] == 'B') b.push_back(i);
  }


  ll res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n-1; ++j) {
      if(s[i] == s[j]) continue;
      // cout << i << ' ' << j << endl;
      char t = f(s[i], s[j]);
      int x = j - i;
      int num = 0;
      if(t == 'R'){
        num = int(r.size()) - (upper_bound(ALL(r), j) - r.begin());
        if(j+x < n && s[j+x] == 'R') num--;
      }
      if(t == 'G'){
        num = int(g.size()) - (upper_bound(ALL(g), j) - g.begin());
        if(j+x < n && s[j+x] == 'G') num--;
      }
      if(t == 'B'){
        // cout << upper_bound(ALL(b), j) - b.begin() << endl;
        num = int(b.size()) - (upper_bound(ALL(b), j) - b.begin());
        if(j+x < n && s[j+x] == 'B') num--;
      }
      // cout << num << endl;
      res += num;
    }
  }
  cout << res << endl;
}
