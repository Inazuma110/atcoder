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
  int n, m;
  cin >> n >> m;
  vector<pair<int, string>> v(m);
  rep(i, m){
    cin >> v[i].first >> v[i].second;
    v[i].first--;
  }
  vector<bool> ac(n, false);
  ll res1 = 0, res2 = 0;
  vector<int> pena(n);

  for (int i = 0; i < m; i++) {
    int num = v[i].first;
    bool isac = (v[i].second == "AC");
    if(!ac[num]){
      if(isac){
        ac[num] = true;
        res2+=pena[num];
        res1++;
      }else{
        pena[num]++;
      }
    }
    // cout << res1 << ' ' << pena << endl;
  }

  cout << res1 << ' ' << res2 << endl;

}
