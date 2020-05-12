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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<pair<char, char>> v(q);
  map<char, ll> maxv;
  map<char, ll> minv;
  map<char, ll> now;

  for(char i = 'A'; i <= 'Z'; i++){
    maxv[i] = 0;
    minv[i] = 0;
  }

  for (int i = 0; i < q; i++){
    cin >> v[i].first >> v[i].second;
    char t = v[i].first;
    char d = v[i].second;
    if(d == 'L'){
      now[t]--;
    }else{
      now[t]++;
    }
    maxv[t] = max(maxv[t], now[t]);
    minv[t] = min(minv[t], now[t]);
  }

  ll res = n;
  for (int i = 0; i < n; i++) {
    char nowc = s[i];
    if(i + minv[nowc] < 0 || i + maxv[nowc] > n-1) res--;
  }

  print(maxv);
  print(minv);
  print(now);

  cout << res << endl;
}
