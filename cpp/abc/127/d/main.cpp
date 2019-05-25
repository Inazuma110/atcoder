#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  map<ll, ll> v;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    v[tmp]++;
  }
  for (int i = 0; i < m; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    v[tmp2] += tmp1;
  }
  ll res = 0;

  ll count = 0;
  ll before = 0;

  for(auto i = v.rbegin(); i != v.rend() ; i++){
    before = count;
    count += i->second;
    if(count <= n){
      res += i->first * i->second;
    }else{
      res += i->first * (n - before);
      break;
    }
  }

  cout << res << endl;




}
