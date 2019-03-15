#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
#include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<ll, ll> p;

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  ll g = gcd(a, b);
  return a / g * b;
}

int main(){
  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  ll l = lcm(n, m);
  // ll g = gcd(n, m);
  if(n < m){
    swap(s, t);
    swap(n, m);
  }

  int save = 0;
  for (int i = 0; i < n; i++) {
    int s_num = i * l / n;
    char s_c = s[i];
    for (int j = save; j < m; j++) {
      int t_num = j * l / m;
      char t_c = t[j];
      // cout << s_num << endl;
      // cout << s_c << endl;
      // cout << t_num << endl;
      // cout << t_c << endl;
      if(s_num == t_num && s_c != t_c){
        cout << -1 << endl;
        return 0;
      }
      if(t_num >= s_num) {
        save = j;
        break;
      }
    }
  }

  cout << l << endl;

}
