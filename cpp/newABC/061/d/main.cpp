#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;
vector<ll> x(1010);
vector<ll> copy_x(1010);

void x_init(){
  x[0] = 0;
  for (int i = 1; i < 1010; i++) {
    x[i] = -LLONG_MAX;
  }
}

set<int> use;
ll n, m;
vector<int> A;
vector<int> B;
vector<int> C;

void dfs(int from, set<int> tmp){
  // print(tmp);
  // cout << from << endl;
  if(from == n-1){
    use.insert(tmp.begin(), tmp.end());
    return;
  }

  for (int i = 0; i < m; i++) {
    if(A[i] == from) {
      if(tmp.count(B[i]) == 1) return;
      if(use.count(B[i]) == 1) return;
      tmp.insert(A[i]);
      tmp.insert(B[i]);
      dfs(B[i], tmp);
      tmp.erase(A[i]);
      tmp.erase(B[i]);
    }
  }
  return;
}


int main(){
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  vector<int> c(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }

  A = a;
  B = b;
  C = c;

  x_init();

  set<int> tmp;
  dfs(0, tmp);


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(use.count(b[j]) == 1)
        x[b[j]] = max(x[b[j]], x[a[j]] + c[j]);
      // if(x[b[j]] > LLONG_MAX - INT_MAX - INT_MAX){
      //   cout << "inf" << endl;
      //   return 0;
      // }
    }
  }

  for (int i = 0; i < 1010; i++) {
    copy_x[i] = x[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(use.count(b[j]) == 1)
        copy_x[b[j]] = max(copy_x[b[j]], copy_x[a[j]] + c[j]);
      // if(x[b[j]] > LLONG_MAX - INT_MAX - INT_MAX){
      //   cout << "inf" << endl;
      //   return 0;
      // }
    }
  }

  for (int i = 0; i < 1010; i++) {
    if(x[i] != copy_x[i]){
      cout << "inf" << endl;
      return 0;
    }
  }

  cout << x[n-1] << endl;
}
