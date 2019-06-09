#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll l, a, b, m;
  cin >> l >> a >> b >> m;
  string s = "";
  ll sum = 0;
  vector<int> v;
  bool flag = false;
  for (int i = 0; i < l; i++) {
    ll an = a + b * i;
    s += to_string(an);
    sum = stoll(s);
    if(!flag) v.push_back(sum);
    if(sum >= m){
      flag = true;
    }
    cout << s << endl;
    cout << sum % m<< endl;
    sum %= m;
    s = to_string(sum);
    cout << "=====" << endl;
  }
  print(v);

}
