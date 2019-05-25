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
  string s1, s2;
  cin >> n >> s1 >> s2;
  vector<bool> isVertical;
  ll tmp = 1000000007;
  for (int i = 0; i < n; i++) {
    if(s1[i] == s2[i]){
      isVertical.push_back(true);
    }
    else{
      isVertical.push_back(false);
      i++;
    }
  }
  ll res;
  if(isVertical[0]) res = 3;
  else res = 6;


  int vsize = int(isVertical.size());

  for (int i = 1; i < vsize; i++) {
    if(!isVertical[i] && !isVertical[i-1]) res *= 3;
    else if(!isVertical[i-1] && isVertical[i]) res *= 1;
    else if(isVertical[i-1] && isVertical[i]) res *= 2;
    else res *= 2;
    res %= tmp;
  }

  cout << res << endl;

}
