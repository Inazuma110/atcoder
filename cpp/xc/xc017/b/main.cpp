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
  vector<p> v(n, {0, 0});
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  int l = v[0].first;
  int r = v[0].second;

  for (int i = 1; i < n; i++) {
    for (int j = l; ; j++) {
      for (int k = r; k * l < j * r; k++) {
        if(j * r == k * l){

        }
      }
    }

  }

}
