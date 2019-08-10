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
  string s;
  cin >> s;
  string kenban = "WBWBWWBWBWBW";
  kenban += kenban;
  kenban += kenban;
  // cout << kenban << endl;
  int start = -1;
  for (int i = 0; i < 25; i++) {
    bool flag = true;
    for (int j = 0; j < 20; j++) {
      if(kenban[i+j] != s[j]){
        flag = false;
        break;
      }
    }
    if(flag) start = i;
  }
  vector<string> v = {"Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si"};
  cout << v[start % 12] << endl;
}
