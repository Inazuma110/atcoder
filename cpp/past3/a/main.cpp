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
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> point(n);
  vector<int> diff(m, n);
  // iがjを解いたか
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (int i = 0; i < q; ++i) {
    int t, who;
    cin >> t >> who;
    who--;
    if(t == 1){
      ll sum = 0;
      for (int j = 0; j < m; ++j) {
        sum += diff[j] * v[who][j];
      }
      cout << sum << endl;
    }else{
      int prob;
      cin >> prob;
      prob--;
      v[who][prob] = 1;
      diff[prob]--;
    }
  }

}
