#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <iterator>

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
  string s;
  cin >> s;
  if(n % 2 == 1) cout << "No" << endl;
  else{
    bool flag = false;
    for (int i = 0; i < n/2; i++) {
      if(s[i] != s[i+n/2]) flag = true;
    }
    if(flag) cout << "No" << endl;
    else cout << "Yes" << endl;
  }

}
