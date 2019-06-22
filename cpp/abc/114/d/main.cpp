#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

int dp[300][100];

void init(){
  for (int i = 0; i < 300; i++) {
    for (int j = 0; j < 100; j++) {
      dp[i][j] = 0;
    }
  }
}

vector<pair<ll, int>> factoring(ll a){
  vector<pair<ll, int>> v;
  for (int i = 2; i <= a; i++) {
    if(a % i == 0){
      int count = 0;
      while(a % i == 0){
        count++;
        a /= i;
      }
      v.push_back({i, count});
    }
  }
  return v;
}

int main(){
  ll n;
  cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    vector<pair<ll, int>> tmp = factoring(i);
    for(auto a : tmp){
      mp[a.first] += a.second;
    }
  }

  int x = int(mp.size());

  int count = 0;
  int num = 1;
  for(auto a : mp){
    num *= a.second;
    if(num > 75) break;
    dp[count][num] = 0
  }

  for(auto a : mp) cout << a.first << ' ' << a.second << endl;
  ll res = 0;

}
