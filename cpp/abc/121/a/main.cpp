#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

typedef long long ll;
typedef pair<int, int> p;


int main(){
  int h, w;
  int hx, wx;
  cin >> h >> w >> hx >> wx;
  int res = h * w;
  cout << res - h*wx - w*hx + hx*wx << endl;
}
