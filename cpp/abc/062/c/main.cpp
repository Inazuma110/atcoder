#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn int

typedef long long ll;
typedef pair<ll,ll> p;


int main()
{
  long double h, w;
  cin >> h >> w;
  if(int(h) % 3 == 0 || int(w) % 3 == 0){
    cout << 0 << endl;
  }else{
    ll res1 = LLONG_MAX;
    ll res3 = LLONG_MAX;
    for (int i = 1; i < h; i++) {
      ll s1 = ll(w / 2) * i;
      ll s2 = ceil(w / 2) * i;
      ll s3 = w * (h-i);
      res1 = min(res1, max({s1, s2, s3}) - min({s1, s2, s3}));
      ll s4 = w * int((h - i) / 2);
      ll s5 = w * ceil((h - i) / 2);
      res3 = min(res3, max({s3, s4, s5}) - min({s3, s4, s5}));

    }

    ll res2 = LLONG_MAX;
    ll res4 = LLONG_MAX;
    for (int i = 1; i < w; i++) {
      ll s1 = ll(h / 2) * i;
      ll s2 = ceil(h / 2) * i;
      ll s3 = h * (w-i);
      res2 = min(res2, max({s1, s2, s3}) - min({s1, s2, s3}));
      ll s4 = h * int((w - i) / 2);
      ll s5 = h * ceil((w - i) / 2);
      res4 = min(res4, max({s3, s4, s5}) - min({s3, s4, s5}));
    }


    cout << min({res1, res2, res3, res4}) << endl;
  }

}
