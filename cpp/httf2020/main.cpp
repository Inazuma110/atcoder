#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
//
// using boost::multiprecision::cpp_int;
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

int n, m, b;
map<p, char> puted;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void output(){
  cout << puted.size() << endl;
  for(auto a : puted){
    cout << a.first.first << ' ' << a.first.second << ' ' << a.second << endl;
  }
}

void put_guide(int y, int x, char d){
  if(y == -1) y = n-1;
  y %= n;
  if(x == -1) x = n-1;
  x %= n;

  puted[{y, x}] = d;
}

void remove_guide(){
  map<p, char> res;
  for(auto a : puted){
    if(a.second != '@'){
      res[{a.first.first, a.first.second}] = a.second;
    }
  }
  puted = res;
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> b;
  int gy, gx;
  cin >> gy >> gx;
  vector<p> r(m);
  vector<char> c(m);
  rep(i, m) cin >> r[i].first >> r[i].second >> c[i];
  vector<p> block(b);
  rep(i, b) cin >> block[i].first >> block[i].second;

  map<p, bool> is_block;
  for(auto blo : block){
    is_block[{blo.first, blo.second}] = true;
  }


  for (int i = 0; i < m; i++) {
    int y = r[i].first, x = r[i].second;
    char d = c[i];

    for(int i = y+1; i < 2*y; i++){
      int ny = i % n;
      if(is_block[{ny, x}]) break;
      if(ny == gy && d != 'D'){
        put_guide(y, x, 'D');
        break;
      }
    }

    for(int i = y-1; i >= y-n+1; i--){
      int ny = (i >= 0) ? i : n - abs(i);
      if(is_block[{ny, x}]) break;
      if(ny == gy && d != 'U'){
        put_guide(y, x, 'U');
        break;
      }
    }

  }

  // 縦Guide
  for (int i = 0; i < n; i++) {
    for(int j = gy+1; j < 2*gy; j++){
      int y = j % n;
      if(is_block[{y, i}]) {
        if(y == gy+1) break;
        put_guide(y-1, i, 'U');
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for(int j = gy-1; j >= gy-n+1; j--){
      int y = (j >= 0) ? j : n - abs(j);
      if(is_block[{y, i}]) {
        if(y == gy-1) break;
        put_guide(y+1, i, 'D');
        break;
      }
    }
  }

  for (int i = gx+1; i < 2*gx; i++) {
    int x = i % n;
    for(int j = 0; j < n; j++){
      if(puted.count({j, x}) == 1) {
        if(!is_block[{gy, x}]) put_guide(gy, x, 'L');
        break;
      }
    }
    if(is_block[{gy, x}]) break;
  }

  for (int i = gx-1; i >= gy-n+1; i--) {
    int x = (i >= 0) ? i : n - abs(i);
    for(int j = 0; j < n; j++){
      if(puted.count({j, x}) == 1) {
        if(!is_block[{gy, x}]) put_guide(gy, x, 'R');
        break;
      }
    }
    if(is_block[{gy, x}]) break;
  }


  // remove_guide();
  output();
}
