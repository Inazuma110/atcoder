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

  int n;
  string s;
  cin >> n >> s;
  int white_num = 0;
  int black_num = 0;
  for (int i = 0; i < n; i++) {
    if(s[i] == '.') white_num++;
    else black_num++;
  }

  // if(white_num == 0 || black_num == 0){
  //   cout << 0 << endl;
  //   return 0;
  // }

  vector<int> black(n+1, 0);
  vector<int> white(n+1, white_num);

  for (int i = 0; i < n; i++) {
    if(s[i] == '#'){
      black[i+1] = black[i] + 1;
      white[i+1] = white[i];
    }else{
      white[i+1] = white[i] - 1;
      black[i+1] = black[i];
    }
  }


  // int black_num = black[n];
  int res = INT_MAX;
  // print(white);
  // print(black);

  for (int i = 0; i < n+1; i++) {
    res = min(res, black[i] + white[i]);
  }
  cout << res << endl;

}
