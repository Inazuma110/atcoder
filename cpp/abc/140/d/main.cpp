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
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  ll res = 0;
  for (int i = 1; i < n; i++) {
    if(s[i] == 'L' && s[i-1] == 'L') res++;
  }
  for (int i = 0; i < n-1; i++) {
    if(s[i] == 'R' && s[i+1] == 'R') res++;
  }
  res += 2 * k;
  cout << min(n-1, res) << endl;
}
