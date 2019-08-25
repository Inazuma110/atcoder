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
  int n;
  cin >> n;
  vector<int> v(n);
  int mujun = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if(v[i] != i+1) mujun++;
  }
  if(mujun == 2 || mujun == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

}
