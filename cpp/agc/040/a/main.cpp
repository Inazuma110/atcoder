#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
//
// using boost::multiprecision::cpp_int;
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
  cin >> s;
  int n = int(s.size());
  vector<int> count(n+1);

  for (int i = 0; i < n; i++) {
    if(s[i] == '<'){
      count[i+1] = count[i] + 1;
    }
  }
  for (int i = n-1; i >= 0; i--) {
    if(s[i] == '>'){
      count[i] = max(count[i], count[i+1] + 1);
    }
  }

  ll res = 0;
  for(auto a : count){
    res += a;
  }
  cout << res << endl;
}
