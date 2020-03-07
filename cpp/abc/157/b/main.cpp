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
  vector<vector<int>> v(3, vector<int>(3, 0));
  vector<vector<bool>> bingo(3, vector<bool>(3, false));
  rep(i, 3) rep(j, 3){
    cin >> v[i][j];
  }
  int n;
  cin >> n;
  vector<int> b(n);

  rep(i, n){
    cin >> b[i];
    rep(j, 3) rep(k, 3){
      if(v[j][k] == b[i]) bingo[j][k] = true;
    }
  }

  rep(i, 3){
    bool flag = false;
    rep(j, 3){
      if(!bingo[i][j]) flag = true;
    }
    if(!flag){
      cout << "Yes" << endl;
      return 0;
    }
  }

  rep(i, 3){
    bool flag = false;
    rep(j, 3){
      if(!bingo[j][i]) flag = true;
    }
    if(!flag){
      cout << "Yes" << endl;
      return 0;
    }
  }

  if(bingo[0][0] && bingo[1][1] && bingo[2][2]) {
    cout << "Yes" << endl;
    return 0;
  }
  if(bingo[0][2] && bingo[1][1] && bingo[2][0]) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;

}
