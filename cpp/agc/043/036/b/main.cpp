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
  ll res = 0;
  vector<int> v;
  int n = int(s.size());

  rep(i, int(s.size())){
    if(s[i] == 'A') v.push_back(0);
    else if(i <= n-2 && s.substr(i, 2) == "BC") v.push_back(1), i++;
    else v.push_back(-1);
  }
  int index = 0;
  // rep(i, int(v.size())) if(v[i] == 0){
  //   index = i; break;
  // }

  for(int i = 0; i < int(v.size()); i++){
    if(v[i] == 1){
      res += index;
    }
    else if(v[i] == -1) index = 0;
    else if(v[i] == 0) index++;
    // cout << res <<endl;
  }
  cout << res << endl;
}
