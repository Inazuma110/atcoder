#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
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

int nokori;
int kaisu;

vector<int> dp(1001, -1);

void dfs(int step, int nv){
  if(nv > nokori) return;
  if(dp[nv] == 1) return;
  if(nv == nokori) {
    cout << 1 << endl;
    exit(0);
  }
  if(step == kaisu) return;
  dfs(step+1, nv+5);
  dfs(step+1, nv+4);
  dfs(step+1, nv+3);
  dfs(step+1, nv+2);
  dfs(step+1, nv+1);
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  nokori = x % 100;
  kaisu = x / 100;
  dfs(0, 0);
  cout << 0 << endl;
}
