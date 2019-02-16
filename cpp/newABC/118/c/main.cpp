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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(all(v));
  int attacker = v[0];

  while(true) {
    for (int i = 1; i < int(v.size()); i++) {
      v[i] %= attacker;
      if(v[i] == 0){
        v.erase(v.begin() + i);
        i--;
        if(v.size() == 1) {
          break;
        }
      }
    }
    if(v.size() == 1) {
      attacker = v[0];
      break;
    }
    sort(all(v));
    attacker = v[0];
  }

  cout << attacker << endl;




}
