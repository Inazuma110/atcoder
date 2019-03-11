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

  map<char, int> est;
  for(char c : s) est[c]++;
  char max_char = '@';
  int max_num = -1;

  for(auto a : est){
    if(a.second > max_num){
      max_char = a.first;
      max_num = a.second;
    }
  }

  int size = int(s.size());
  int res = 0;

  while(true) {
    if(max_num + res >= size) break;
    for (int i = 0; i < size; i++) {
      if(s[i] == max_char && s[i+1] != max_char) {
        s[i+1] = max_char;
        max_num++;
        i++;
      }
    }
    res++;
  }

  cout << res << endl;


}
