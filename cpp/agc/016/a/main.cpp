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
  string s;
  cin >> s;

  int res = INT_MAX;
  for(char i = 'a'; i <= 'z'; i++){
    string tmp = s;
    int count = 0;
    while(true){
      bool flag = false;
      for (int j = 0; j < int(tmp.size()); j++) {
        if(tmp[j] != i) flag = true;
      }
      if(!flag) break;
      string tmp2 = "";
      count++;
      for (int j = 0; j < int(tmp.size())-1; j++) {
        if(tmp[j] == i || tmp[j+1] == i) tmp2 += i;
        else tmp2 += tmp[j];
      }
      tmp = tmp2;
    }
    // cout << count << endl;
    // cout << i << endl;
    res = min(res, count);
  }

  cout << res << endl;
}
