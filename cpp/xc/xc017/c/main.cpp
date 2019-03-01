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
  // char max_char = '@';
  // int max_num = -1;

  // for(auto a : est){
  //   if(a.second > max_num){
  //     max_char = a.first;
  //     max_num = a.second;
  //   }
  // }

  int size = int(s.size());

  int res = INT_MAX;
  for(char c = 'a'; c <= 'z'; c++){
    string tmp = s;
    int max_num = est[c];
    char max_char = c;
    int count = 0;
    if(est[c] == 0)  continue;

    int begin = tmp.find(c);
    int longest = begin;
    int index = longest;
    for (int i = begin+1; i < size; i++) {
      if(tmp[i] == max_char){
        longest = max(longest, i - index - 1);
        index = i;
      }
    }

    cout << c << endl;

    while(true) {
      count++;
      for (int i = 0; i < size; i++) {
        if(tmp[i] == max_char && tmp[i+1] != max_char) {
          tmp[i+1] = max_char;
          max_num++;
          i++;
        }
      }
      if(max_num + count >= size && longest <= count - begin) break;
      cout << tmp << endl;
    }
    cout << count << endl;
    cout << "======" << endl;
    res = min(res, count);
  }

  cout << res << endl;


}
