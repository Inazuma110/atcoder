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
  vector<p> v(m);
  rep(i, m){
    int from, to;
    cin >> from >> to;
    from--;to--;
    v[i] = {to, from};
  }
  sort(ALL(v));

  int res = 0;
  int right = -1;
  for (int i = 0; i < m; ++i) {
    int l = v[i].second;
    int r = v[i].first;
    if(right <= l){
      res++;
      right = r;
    }
  }
  cout << res << endl;
}
