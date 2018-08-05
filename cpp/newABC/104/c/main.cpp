#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn int

typedef long long ll;
typedef pair<int,int> p;


int main()
{
  int d, g;
  cin >> d >> g;
  vector<p> v(d, {0,0});
  for (int i = 0; i < d; i++)
  {
    cin >> v[i].first >> v[i].second;
  }


  // if (v[d-1].first * d*100 + v[d-1].second >= g)
  // {
    // cout << d << endl;
    // return 0;
  // }

  vector<p> val(d, {0, 0});
  for (int i = 0; i < d; i++)
  {
    val[i].first = ((i+1)*100 * v[i].first + v[i].second) / v[i].first;
    val[i].second = i;
  }

  sort(rall(val));
  int res = INT_MAX;

  if(v[d-1].first * d*100 >= g)
  {
    res = min(res, int(ceil(g / (d * 100))));
  }

  if (v[val[d-1].second].first * d*100 + v[d-1].second >= g)
  {
    res = min(res, v[val[0].second].first);
  }

  // for(auto i : val) cout << i.first << endl;

  int index = 0;
  for (int i = 0; i < d; i++)
  {
    if(g < v[val[i].second].first * 100 * (val[i].second+1) + v[val[i].second].second)
    {
      index = val[i].second;
      break;
    }
    g -= v[val[i].second].first * 100 * (val[i].second+1) + v[val[i].second].second;
    res += v[val[i].second].first;
    // cout << res << endl;
  }

  while(g > 0) {
    res++;
    // cout << index << endl;
    g -= (index + 1) * 100;
    if(g <= 0) break;
  }

  cout << res << endl;

}
