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
  int n;
  cin >> n;
  vector<pair<p, string>> v(n);
  map<int, int> mpl, mpr, mpu, mpd;
  vector<int> lr1, lr2;
  rep(i, n){
    int x, y;
    string d;
    cin >> x >> y >> d;
    v[i] = {{x, y}, d};
    if(d == "l"){
      if(mpl.count(y) == 0) mpl[y] = x;
      else mpl[y] = max(mpl[y], x);
      lr1.push_back(x-y);
      lr1.push_back(y-x);
    }
    if(d == "r"){
      if(mpr.count(y) == 0) mpr[y] = x;
      else mpr[y] = min(mpr[y], x);
      lr1.push_back(x-y);
      lr1.push_back(y-x);
    }
    if(d == "d"){
      if(mpd.count(x) == 0) mpd[x] = y;
      else mpd[x] = max(mpd[x], y);
      lr2.push_back(x-y);
      lr2.push_back(y-x);
    }
    if(d == "u"){
      if(mpu.count(y) == 0) mpu[x] = y;
      else mpd[x] = min(mpd[x], y);
      lr2.push_back(x-y);
      lr2.push_back(y-x);
    }
  }

  for (int i = 0; i <= 200000; ++i) {
    if(mpl[i] > mpr[i] && mpl.count(i) != 0 && mpr.count(i) != 0) cout << "Not safe" << endl;
  }
  for (int i = 0; i <= 200000; ++i) {
    if(mpu[i] < mpd[i] && mpu.count(i) != 0 && mpd.count(i) != 0) cout << "Not safe" << endl;
  }


}
