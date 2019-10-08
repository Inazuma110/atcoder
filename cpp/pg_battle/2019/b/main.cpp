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
  if(s == "AtCoder"){
    cout << "Yes" << endl;
    return 0;
  }
  string atcoder = "atcoder";
  for (int i = 0; i < 7; i++) {
    if(s[i] != atcoder[i] && s[i] != atcoder[i] - 0x20){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Maybe" << endl;
}
