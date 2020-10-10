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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<ll> sum(n+1, 0);

  map<ll, ll> mp;
  mp[0]++;
  for (int i = 0; i < n; i++) {
    sum[i+1] = v[i] + sum[i];
    mp[sum[i+1]]++;
  }

  ll res = 0;
  for(auto a : mp){
    if(a.second >= 2) res += comb(a.second, 2);
  }
  cout << res << endl;

}
