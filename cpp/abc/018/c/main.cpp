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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c, k;
  cin >> r >> c >> k;
  vector<string> v(r);
  rep(i, r) cin >> v[i];
  ll res = 0;

  vector<vector<p>> is1(r, vector<p>(c));

  for (int i = 0; i < c; i++) {
    int count = 0;
    for (int j = 0; j < r; j++) {
      if(v[j][i] == 'o') count++;
      else count = 0;
      is1[j][i].first = count;
    }
  }

  for (int i = 0; i < c; i++) {
    int count = 0;
    for (int j = r-1; j >= 0; j--) {
      if(v[j][i] == 'o') count++;
      else count = 0;
      is1[j][i].second = count;
    }
  }

  // print(is1);
  for (int i = k-1; i < r - k+1; i++) {
    for (int j = k-1; j < c - k+1; j++) {
      // cout << i << " : " << j << endl;
      bool flag = true;
      for (int l = j - (k-1); l < j + k; l++) {
        int d = abs(j - l);
        if(is1[i][l].first < k - d || is1[i][l].second < k - d){
          flag = false;
          break;
        }
      }
      if(flag) res++;
      // cout << "===" << endl;
    }

  }
  cout << res << endl;


}
