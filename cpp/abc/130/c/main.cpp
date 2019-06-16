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
  long double w, h, x, y;
  cin >> w >> h >> x >> y;
  cout << w * h * 0.5 << ' ';
  cout << (x == w/2 && y == h/2) << endl;
}
