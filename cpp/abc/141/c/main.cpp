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
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> v(q);
  rep(i, q) {
    cin >> v[i];
    v[i]--;
  }
  map<int, int> count;
  rep(i, q){
    count[v[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if(k - (q - count[i]) > 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}
