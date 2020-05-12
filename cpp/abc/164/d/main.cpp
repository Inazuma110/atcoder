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
  string s;
  cin >> s;
  int n = int(s.size());
  reverse(ALL(s));
  int x = 1, tot = 0;
  // vector<ll> cnt(2019);
  map<int, ll> cnt;
  ll res = 0;
  rep(i, n){
    cnt[tot]++;
    // cout << tot << endl;
    // print(cnt);
    tot += (s[i]-'0')*x;
    tot %= 2019;
    res += cnt[tot];
    x = x*10%2019;
  }
  cout << res << endl;
}
