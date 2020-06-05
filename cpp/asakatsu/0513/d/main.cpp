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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string name, kit;
  cin >> name >> kit;
  map<char, double> name_map;
  map<char, double> kit_map;
  for(auto a : name) name_map[a]++;
  for(auto a : kit) kit_map[a]++;
  int res = 0;
  for(char c = 'A'; c <= 'Z'; c++){
    if(kit_map[c] == 0 && name_map[c] >= 1) {
      cout << -1 << endl;
      return 0;
    }
    chmax(res, int(ceil(name_map[c] / kit_map[c])));
  }
  cout << res << endl;
}
