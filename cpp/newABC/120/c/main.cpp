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
  int zero = 0;
  int one = 0;
  for(auto a : s){
    if(a == '0') zero++;
    if(a == '1') one++;
  }
  cout << min(zero, one) * 2 << endl;
}

