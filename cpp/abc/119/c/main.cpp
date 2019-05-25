#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

int main(){
  ll a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a);
  vector<ll> t(b);
  vector<ll> x(q);
  for (int i = 0; i < a; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < b; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> x[i];
  }

  for (int i = 0; i < q; i++) {
    ll res = 0;
    ll s_index = lower_bound(all(s), x[i]) - s.begin();
    vector<ll> hikaku;
    if(s_index == a) s_index = a-1;
    // hikaku.push_back(abs(x[i] - s[s_index]));
    // if(s_index != 0) hikaku.push_back(abs(x[i] - s[s_index-1]));
    // if(s_index != a-1) hikaku.push_back(abs(x[i] - s[s_index+1]));
    hikaku.push_back(abs( - s[s_index]));
    if(s_index != 0) hikaku.push_back(abs( - s[s_index-1]));
    if(s_index != a-1) hikaku.push_back(abs( - s[s_index+1]));

    ll t_index = lower_bound(all(t), x[i]) - t.begin();
    vector<ll> hikaku2;
    if(t_index == b) t_index = b-1;
    // hikaku2.push_back(abs(x[i] - t[t_index]));
    // if(t_index != 0) hikaku2.push_back(abs(x[i] - t[t_index-1]));
    // if(t_index != b-1) hikaku2.push_back(abs(x[i] - t[t_index+1]));
    hikaku2.push_back(abs( - t[t_index]));
    if(t_index != 0) hikaku2.push_back(abs( - t[t_index-1]));
    if(t_index != b-1) hikaku2.push_back(abs( - t[t_index+1]));

    ll minv = LLONG_MAX;
    for(ll tmp : hikaku){
      for(ll tmp2 : hikaku2){
        ll now = x[i];
        minv = min(minv, (abs(tmp - now) + abs(tmp - tmp2)));
        minv = min(minv, (abs(tmp2 - now) + abs(tmp2 - tmp)));
      }
    }
    res += minv;
    // res += *min_element(all(hikaku2));
    // cout << x[i] << endl;
    // print(hikaku);
    // print(hikaku2);
    cout << res << endl;
    // cout << endl;
  }


}
