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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int is_big = -1;
  int res = 0;
  for (int i = 0; i < n-1; i++) {
    if(is_big == -1){
      if(v[i] == v[i+1]) continue;
      else if(v[i+1] < v[i]) is_big = 0;
      else is_big = 1;
    }else if(is_big == 1 && v[i+1] < v[i]){
      res++;
      is_big = -1;
    }else if(is_big == 0 && v[i+1] > v[i]){
      res++;
      is_big = -1;
    }
  }
  cout << res+1 << endl;
}
