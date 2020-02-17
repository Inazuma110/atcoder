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
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  string all_tate_b = string(h, '#');
  string all_tate_w = string(h, '.');

  string all_yoko_b = string(w, '#');
  string all_yoko_w = string(w, '.');

  int is_yoko_black[h];
  int is_yoko_white[h];

  int is_tate_black[w];
  int is_tate_white[w];

  rep(i, h){
    cin >> v[i];
    is_yoko_black[i] = v[i] == all_yoko_b;
    is_yoko_white[i] = v[i] == all_yoko_w;
  }

  rep(j, w){

  }
}
