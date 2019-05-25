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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> vv(n,vector<int>());
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int vsize;
    cin >> vsize;
    for (int j = 0; j < vsize; j++) {
      int tmp;
      cin >> tmp;
      mp[tmp]++;
      vv[i].push_back(tmp);
    }
  }

  int res = 0;
  for(auto a : mp){
    if(a.second == n) res++;
  }

  cout << res << endl;
}
