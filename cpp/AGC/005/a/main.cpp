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
  // int s_num = 0;
  // int t_num = 0;
  int count = 0;
  int res = 0;
  for(auto a : s){
    if(a == 'S') count++;
    else if(a == 'T' && count >= 1) {
      count--;
      res++;
    }
  }
  cout << int(s.size()) - res * 2 << endl;


}
