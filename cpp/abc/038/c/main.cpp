#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
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
  ll increase = 1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  ll res = n;

  for (int i = 1; i < n; i++) {
    if(v[i] > v[i-1]){
      increase++;
    }else{
      res += (increase * (increase - 1)) / 2;
      increase = 1;
    }
  }
  res += (increase * (increase - 1)) / 2;

  cout << res << endl;

}
