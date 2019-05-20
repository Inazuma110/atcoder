#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;

int dp[1000100];

void init(){
  for (int i = 0; i < 1000100; i++) {
    dp[i] = -100;
  }
}

int rec(int x, int y, int z){
  if(dp[y] != -100) return dp[y];
  else if(x <= y) return dp[y] = y;
  else{
    return dp[y] = rec(
        rec(x-1, y, z),
        rec(y-1, z, x),
        rec(z-1, x, y)
        );
  }
}


int main(int argc, char *argv[]){
  int x = stoi(argv[1]);
  int y = stoi(argv[2]);
  int z = stoi(argv[3]);
  init();
  ll res = rec(x, y, z);
  cout << res << endl;
}
