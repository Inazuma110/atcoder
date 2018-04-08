#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> p;

int main()
{
  int q;
  cin >> q;
  ll tmp1,tmp2;
  ll res = 0;
  vector<p> v(q, {0,0});
  for (int i = 0; i < q; i++){
    cin >> tmp1 >> tmp2;
    v[i] = make_pair(tmp1, tmp2);
  }

  for (int i = 0; i < q; i++){
    long double tmp = pow(v[i].first * v[i].second, 0.5);
    ll total = v[i].first * v[i].second;
    // ll hoge = v[i].first * v[i].second;
    ll sqrtTmp = int(tmp);
    // cout << sqrtTmp << endl;
    res = (sqrtTmp - 1) * 2;
    if (tmp == sqrtTmp && v[i].first != v[i].second) {
      res--;
    }
    if ((sqrtTmp-1)*(sqrtTmp+2) < total && abs(v[i].first - v[i].second) != 1) {
      res++;
    }


    // if (sqrtTmp == v[i].first && v[i].first == v[i].second) {
    //   res = (sqrtTmp-1) * 2;
    //   cout << "3x3" << endl;
    // }else if (tmp - sqrtTmp == 0) {
    //   res = (sqrtTmp - 2) * 2 + 1;
    //   cout << "x^2" << endl;
    // }else{
    //   res = (sqrtTmp-1) * 2 + 1;
    //   cout << "other" << endl;
    // }
    cout << res << endl;
  }
  return 0;
}
