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
  int a, b;
  cin >> a >> b;
  int count = 0;
  for(int i = a; i <= b; i++){
    string tmp = to_string(i);
    if(tmp[0] == tmp[4] && tmp[1] == tmp[3]) count++;
  }
  cout << count << endl;
}
