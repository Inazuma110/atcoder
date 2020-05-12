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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> v(h);
  vector<vector<int>> res(h, vector<int> (w, 1));
  // bool all_white = true;
  vector<bool> all_white(h, true);
  int start = -1;
  rep(i, h){
    cin >> v[i];
    rep(j, w) if(v[i][j] == '#'){
      all_white[i] = false;
      if(start == -1) start = i;
    }
  }
  int count = 1;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      res[i][j] = count;
      if(v[i][j] == '#'){
        count++;
      }
    }

    if(!all_white[i]){
      for (int k = w-1; k >= 0; k--) {
        if(res[i][k] == count-1) break;
        res[i][k] = count-1;
      }
    }
  }

  for (int i = start+1; i < h; i++) {
    if(all_white[i]){
      for (int j = 0; j < w; j++) {
        res[i][j] = res[i-1][j];
      }
    }
  }
  for (int i = start-1; i >= 0; i--) {
    if(all_white[i]){
      for (int j = 0; j < w; j++) {
        res[i][j] = res[i+1][j];
      }
    }
  }

  rep(i, h){
    rep(j, w){
      cout << res[i][j] << '\t';
    }
    cout << endl;
  }
}
