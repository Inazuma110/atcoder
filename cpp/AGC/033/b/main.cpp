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

  int h, w, n;
  cin >> h >> w >> n;
  int sr, sc;
  cin >> sr >> sc;
  string s, t;
  cin >> s >> t;

  int ny = sr;
  int nx = sc;

  for (int i = 0; i < n; i++) {
    if(s[i] == 'R'){
      if(nx == w){
        // cout << ny << endl;
        // cout << nx << endl;
        cout << "NO" << endl;
        return 0;
      }else{
        nx++;
      }
    }
    if(t[i] == 'L'){
      if(nx != 1){
        nx--;
      }
    }

    if(s[i] == 'D'){
      if(ny == h){
        cout << "NO" << endl;
        return 0;
      }else{
        ny++;
      }
    }
    if(t[i] == 'U'){
      if(ny != 1){
        ny--;
      }
    }
  }

  ny = sr;
  nx = sc;

  for (int i = 0; i < n; i++) {
    if(s[i] == 'L'){
      if(nx == 1){
        cout << "NO" << endl;
        return 0;
      }else{
        nx--;
      }
    }
    if(t[i] == 'R'){
      if(nx != w){
        nx++;
      }
    }

    if(s[i] == 'U'){
      if(ny == 1){
        cout << "NO" << endl;
        return 0;
      }else{
        ny--;
      }
    }
    if(t[i] == 'D'){
      if(ny != h){
        ny++;
      }
    }
  }

  cout << "YES" << endl;

}
