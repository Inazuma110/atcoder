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
  string s;
  cin >> s;
  // if(s == "zyxwvutsrqponmlkjihgfedcba"){
  //   cout << -1 << endl;
  //   return 0;
  // }

  map<char, bool> mp;
  for(char c : s){
    mp[c] = true;
  }

  char tmp = '@';
  for(char c = 'a'; c <= 'z'; c++){
    if(!mp[c]){
      tmp = c;
      break;
    }
  }

  if(tmp != '@') {
    cout << s << tmp << endl;
    return 0;
  }

  vector<char> tmp2(1, s[25]);
  s = s.substr(0, 25);
  for (int i = 24; i >= 0; i--) {
    // cout << s << endl;
    // print(tmp2);
    for (int j = 0; j < int(tmp2.size()); j++) {
      if(s[i] < tmp2[j]){
        s = s.substr(0, int(s.size())-1);
        cout << s << tmp2[j] << endl;
        return 0;
      }
    }
    tmp2.push_back(s[i]);
    sort(all(tmp2));
    s = s.substr(0, int(s.size())-1);
  }
  cout << -1 << endl;
}

