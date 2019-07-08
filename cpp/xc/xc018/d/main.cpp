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
  string s;
  int k;
  cin >> s >> k;
  string s2 = s;
  sort(ALL(s2));
  set<string> v;
  int n = int(s.size());

  for (int i = 0; i < n; i++) {
    for (int j = 1; i + j <= n; j++) {
      string tmp = s.substr(i, j);
      v.insert(tmp);
    }
  }

  vector<string> vec2(v.begin(), v.end());
  sort(ALL(vec2));

  cout << vec2[k-1] << endl;
}
