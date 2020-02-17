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

ll n;
ll resv = 0;

ll dp[100][100];


ll f(int start, int end){
  // cout << start << ' ' << end << endl;
  ll tmpv = 0;
  if(start == 0) return 0;

  if(start == end && start <= n) {
    resv++;
    tmpv++;
  }

  // cout << stoi(to_string(start) + to_string(end)) << endl;
  if(stoi(to_string(start) + to_string(end)) <= n) {
    resv++;
    tmpv++;
  }

  for (int i = 0; i < 10000; i++) {
    string tmp = to_string(i);
    string res = to_string(start) + tmp + to_string(end);
    if(stoi(res) <= n){
      resv++;
      tmpv++;
    }
    if(i < 1000){
      tmp = "0" + to_string(i);
      res = to_string(start) + tmp + to_string(end);
      if(stoi(res) <= n){
        resv++;
        tmpv++;
      }
    }

    if(i < 100){
      tmp = "00" + to_string(i);
      res = to_string(start) + tmp + to_string(end);
      if(stoi(res) <= n){
        resv++;
        tmpv++;
      }
    }

    if(i < 10){
      tmp = "000" + to_string(i);
      res = to_string(start) + tmp + to_string(end);
      if(stoi(res) <= n) {
        resv++;
        tmpv++;
      }
    }
  }
  return dp[start][end] = tmpv;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      dp[i][j] = -1;
    }
  }

  for (int i = 1; i <= n; i++) {
    if(i < 10) f(i, i);
    else {
      int n = int(to_string(i).size());
      if(dp[to_string(i)[n-1] - '0'][to_string(i)[0] - '0'] == -1)
        f(to_string(i)[n-1] - '0', to_string(i)[0] - '0');
      else resv += dp[to_string(i)[n-1] - '0'][to_string(i)[0] - '0'];
    }
    // cout << resv << endl;
  }

  cout << resv << endl;
}
