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
  int n;
  cin >> n;
  vector<p> v(n);
  vector<p> time(n);
  rep(i, n){
    cin >> v[i].first >> v[i].second;
    time[i].second = v[i].first - v[i].second;
    time[i].first = v[i].first + v[i].second;
  }
  sort(ALL(time));
  ll res = n;

  int bi = 0;
  int tmp = 0;
  for (int i = 1; i < n; i++) {
    int start = time[i].second;
    // int end = time[i].first;
    if(start < time[bi].first) {
      // cout << i << endl;
      res--;
      tmp++;
    }else{
      bi += tmp+1;
      tmp = 0;
    }
  }

  cout << res << endl;
}
