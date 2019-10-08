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
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  vector<vector<bool>> v(h, vector<bool> (w, false));
  vector<int> count(w);

  if(a == 0 && b == 0){
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if(v[i][j]) cout << 1;
        else cout << 0;
      }
      cout << endl;
    }
    return 0;
  }

  for (int i = 0; i < w; i++) {
    if(i < w - a) v[0][i] = true;
  }

  for (int i = 1; i < h; i++) {
    int c0 = 0, c1 = 0;
    for (int j = 0; j < w; j++) {
      if((c1 < c0 && c1 < a) || (c0 < c1 &&  c0 == a)){
        if((count[j] < h - count[j] && count[j] < b) || count[j] > h - count[j]){
          v[i][j] = true;
          // print(v);
        }
      }
      if(c1 + (w-j) == a){
        v[i][j] = true;
      }
      if(!v[i][j]) c0++;
      else c1++;
      if(v[i][j]) count[j]++;
    }
    print(v);
  }

  vector<int> counth(h);
  vector<int> countw(w);
  for (int i = 0; i < w; i++) {
    if(min(count[i], h-count[i]) != b){
      cout << "No" << endl;
      return 0;
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if(v[i][j]) cout << 1;
      else cout << 0;
    }
    cout << endl;
  }
}
