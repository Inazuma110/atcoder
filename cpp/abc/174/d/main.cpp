#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

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

int f(int x) {
  return 10 * x + 7;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll count = 0;
  for (int i = 0; i < n; ++i) {
    if(s[i] == 'W') count++;
  }
  ll res = min(count, n-count);
  int countW, countR = 0;
  vector<int> vW, vR;
  for (int i = 0; i < n; ++i) {
    if(s[i] == 'W'){
      countW++;
      vW.push_back(i);
    }
  }
  for (int i =0; i < n; i++) {
    if(s[i] == 'R'){
      countR++;
      vR.push_back(i);
    }
  }

  int ind = int(vR.size())-1;
  count = 0;
  // print(vW);
  // print(vR);
  if(vW.size() == 0 || vR.size() == 0){
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < int(vW.size()); ++i) {
    if(vW[i] < vR[ind]){
      swap(s[vW[i]], s[vR[ind]]);
      ind--;
      count++;
    }
  }
  chmin(res, count);

  cout << res << endl;

}
