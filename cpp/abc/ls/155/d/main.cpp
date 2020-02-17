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
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  vector<ll> plus;
  vector<ll> minous;
  rep(i, n){
    cin >> v[i];
    if(v[i] < 0) minous.push_back(v[i]);
    if(v[i] >= 0) plus.push_back(abs(v[i]));
  }
  sort(ALL(v));
  sort(ALL(plus));
  sort(ALL(minous));
  ll plus_size = n-int(minous.size());

  if(int(minous.size()) * plus_size >= k){
    ll l = minous[k/plus_size];
    ll r = plus[k%plus_size];
    cout << l * r << endl;
  }else{
    k -= plus_size;
    ll pluses = int(plus.size());
    ll l = plus[k/pluses];
    ll r = plus[k%pluses];
    cout << l * r << endl;
  }

}
