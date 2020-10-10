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
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  ll res = 0;
  sort(all(v));

  bool new_bus = true;
  int bus_num = 0;
  int wait_time = 0;
  int now = 0;
  int first_num = 0;
  for (int i = 0; i < n; i++) {
    now = v[i];
    if(new_bus){
      bus_num = 0;
      wait_time = 0;
      first_num = i;
      new_bus = false;
    }
    bus_num++;
    wait_time = now - v[first_num];
    // cout << wait_time << endl;
    // cout << bus_num << endl;
    if(bus_num > c || wait_time > k){
      res++;
      // cout << "go" << endl;
      new_bus = true;
      i--;
    }
    // cout << "======" << endl;
  }
  res++;
  cout << res << endl;
}
