#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
// using namespace atcoder;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
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
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  vector<ll> sums((n * (n + 1)) / 2);

  ll count = 0;
  rep(i, n){
    for (int j = i; j < n; ++j) {
      for (int k = i; k <= j; ++k) {
        sums[count] += v[k];
      }
      count++;
    }
  }
  sort(RALL(sums));
  vector<int> bits(60);
  rep(i, sums.size()) rep(j, 60) bits[j] += (bool)(sums[i] & (1ll << j));

  //-1 utagau 0 kaku 1 utagau
  vector<int> kouho(sums.size(), -1);
  count = (ll)sums.size();

  for (int i = 59; i >= 0; i--) {
    if(bits[i] < k) continue;
    ll tmp = 0;
    for (int j = 0; j < (int)sums.size(); ++j) {
      if(!kouho[j]) continue;
      if((sums[j] & (1ll << i))){
        kouho[j] = 1;
        tmp++;
      }
    }

    if(tmp > k){
      rep(j, sums.size()){
        kouho[j] = kouho[j] == 1 ? 2 : 0;
      }
    }

    if(tmp < k){
      rep(j, sums.size()) if(kouho[j] == 1) kouho[j] = -1;
    }

    if(tmp == k){
      ll res = 0;
      rep(j, 40) res += (1ll << j);
      rep(j, sums.size()) if(kouho[j] == 1) res = res & sums[j];
      cout << res << endl;
      exit(0);
    }
  }

  ll res = 0;
  rep(j, 40) res += (1ll << j);
  rep(i, sums.size()){
    if(kouho[i] != 0 && k > 0) res = (res & sums[i]), k--;
  }
  cout << res << endl;

}
