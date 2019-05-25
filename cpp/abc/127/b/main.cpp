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
  int r, d, x;
  cin >> r >> d >> x;
  int before = x;
  for (int i = 1; i <= 10; i++) {
    cout << r*before - d << endl;
    before = r*before - d;
  }
}
