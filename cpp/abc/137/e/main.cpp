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
typedef pair<int, int> p;

vector<int> to(2505);
vector<int> rto(2505);
vector<bool> reach1(2505);
vector<bool> reach_n(2505);

void dfs(int v){
  if(reach1[v]) return;
  reach1[v] = true;
}

int main(){

}
