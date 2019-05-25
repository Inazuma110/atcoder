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
  int d;
  cin >> d;
  if(d == 25) cout << "Christmas" << endl;
  if(d == 24) cout << "Christmas Eve" << endl;
  if(d == 23) cout << "Christmas Eve Eve" << endl;
  if(d == 22) cout << "Christmas Eve Eve Eve" << endl;
}
