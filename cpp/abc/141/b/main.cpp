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
  cin >> s;
  bool flag = false;
  for (int i = 0; i < int(s.size()); i++) {
    if(i % 2 == 0){
      if(s[i] == 'R' || s[i] == 'U' || s[i] == 'D') continue;
      flag = true;
    }else{
      if(s[i] == 'L' || s[i] == 'U' || s[i] == 'D') continue;
      flag = true;
    }
  }
  if(!flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
