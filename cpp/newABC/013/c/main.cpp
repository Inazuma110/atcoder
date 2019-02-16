#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

int main(){
  long double n, h, a, b, c, d, e;
  cin >> n >> h >> a >> b >> c >> d >> e;

  bool isRich = (a / b < c / d);
  ll pay = 0;

  if(int(h) / int(e) > n){
    cout << 0 << endl;
    return 0;
  }

  n -= (int(h) / int(e));
  h -= (int(h) / int(e)) * int(e);

  ll husoku = n * e;
  ll kaisu = 0;


  if(isRich){
    kaisu = husoku / int(b);
    pay += kaisu * a;
    h -= kaisu * b;
  }
  else {
    kaisu = husoku / int(d);
    pay += kaisu * c;
    h -= kaisu * d;
  }

  if(h > d){
    int tmp1 = pay + a;
    int tmp2 = pay + 2 * b;
    pay = min(tmp1, tmp2);
  }else if(h != 0){
    pay += c;
  }
  cout << pay << endl;
}
