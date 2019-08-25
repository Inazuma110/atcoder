#include <bits/stdc++.h>
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

int n, m;
vector<int> imos;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vector<int> l(n), r(n), s(n);
  ll res = 0;
  imos = vector<int> (m+1);
  rep(i, n) {
    cin >> l[i] >> r[i] >> s[i];
    l[i]--;r[i]--;
    imos[l[i]] += s[i];
    imos[r[i]+1] -= s[i];
    res += s[i];
  }
  for (int i = 1; i < m+1; i++) {
    imos[i] += imos[i-1];
  }
  imos.pop_back();
  // print(imos);
  cout << res - *min_element(ALL(imos)) << endl;
}
