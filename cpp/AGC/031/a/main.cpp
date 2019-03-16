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

long long comb(int n, int r) {
  if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
  long long ans = 1;

  for(int i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }

  return ans;
}


int main(){
  ll n;
  string s;
  cin >> n >> s;
  map<char, ll> mp;
  for(char c : s){
    mp[c]++;
  }
  ll res = 0;

  for (int i = 0; i < n; i++) {
    res += comb(n, i+1);
    for(auto a : mp){
      if(n-a.second >= && a.second >= 2){
        res -= comb(a.second, i+1);
      }
    }
    res %= MOD;
  }

  cout << res << endl;

}
