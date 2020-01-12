#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

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
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> v(n);
  ll sum = 0;
  rep(i, n-1){
    cin >> v[i];
    sum += v[i];
  }
  ll tmp = n * m;
  if(tmp - sum <= k) cout << max(0ll, tmp - sum) << endl;
  else cout << -1 << endl;

}
