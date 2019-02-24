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
  string tmp = s;
  int month = stoi(s.substr(5, 2));
  int day = stoi(tmp.substr(9, 2));

  if(month < 4) cout << "Heisei" << endl;
  else if(month == 4 && day <= 30) cout << "Heisei" << endl;
  else cout << "TBD" << endl;

}
