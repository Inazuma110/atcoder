#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<long double, long double> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<p> v(n);
  map<p, int> mp;
  map<int, int> mp2;
  map<int, int> mp3;

  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }


  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      p tmp1 = v[i];
      p tmp2 = v[j];
      p diff = {tmp1.first-tmp2.first, tmp1.second-tmp2.second};
      mp[diff]++;
      // diff = {-tmp1.first+tmp2.first, -tmp1.second-tmp2.second};
      diff.first *= -1;
      diff.second *= -1;
      mp[diff]++;
    }
  }

  // int res = 0;
  int maxv = -1;
  for(auto a : mp){
    maxv = max(maxv, a.second);
  }

  if(n == 1) cout << 1 << endl;
  else cout << max(n-maxv, 1) << endl;

}
