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
typedef pair<ll, ll> p;

int n;

void dfs(string x, int step){
  if(step == n){
    cout << x << endl;
    return;
  }
  dfs(x + 'a', step+1);
  dfs(x + 'b', step+1);
  dfs(x + 'c', step+1);
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  dfs("", 0);
}
