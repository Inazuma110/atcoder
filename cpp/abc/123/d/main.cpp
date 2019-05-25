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

int x, y, z;
vector<ll> all;
vector<ll> all_tmp;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> x >> y >> z;
  ll k;
  cin >> k;
  vector<ll> a(x);
  vector<ll> b(y);
  vector<ll> c(z);
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < y; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < z; i++) {
    cin >> c[i];
  }

  sort(RALL(a));
  sort(RALL(b));
  sort(RALL(c));

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      all.push_back(a[i] + b[j]);
    }
  }
  sort(RALL(all));

  all_tmp = vector<ll> (k);
  for (int i = 0; i < k; i++) {
    if(i >= int(all.size())) break;
    all_tmp[i] = all[i];
  }
  sort(RALL(all_tmp));
  all = vector<ll>();

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < z; j++) {
      all.push_back(all_tmp[i] + c[j]);
    }
  }
  sort(RALL(all));

  for (int i = 0; i < k; i++) {
    cout << all[i] << endl;
  }




}
