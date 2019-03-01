#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

bool check_sosu(int a){
  if(a == 0 || a == 1) return false;
  if(a == 2) return true;
  int tmp = pow(a, 0.5) + 2;
  for (int i = 2; i < tmp && i < a; i++) {
    if(a % i == 0) return false;
  }
  return true;

}

int main(){
  int q;
  cin >> q;
  vector<bool> sosu(100100, false);
  vector<int> sosu_num(100100, 0);

  for (int i = 1; i < 100100; i++) {
    sosu[i] = check_sosu(i);
  }
  for (int i = 100099; i >= 3; i--) {
    if(sosu[i] && sosu[(i+1)/2]) sosu[i] = true;
    else sosu[i] = false;
  }
  sosu[0] = false;
  sosu[1] = false;
  sosu[2] = false;
  sosu[3] = true;

  for (int i = 1; i < 100100; i++) {
    if(sosu[i]) sosu_num[i] = sosu_num[i-1]+1;
    else sosu_num[i] = sosu_num[i-1];
  }



  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    // if(l == r) cout << sosu[l] << endl;
    // else if()
    cout << sosu_num[r] - sosu_num[l-1] << endl;
  }



}
