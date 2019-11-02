#include <bits/stdc++.h>
#include <sys/ucontext.h>
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

int dp[100010];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<p> v(n);
  vector<p> v2(n);

  rep(i, n){
    cin >> v[i].second >> v[i].first;
    v2[i].first = v[i].second;
    v2[i].second = v[i].first;
  }
  sort(RALL(v));
  sort(RALL(v2));


}
