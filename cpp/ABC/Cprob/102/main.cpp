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
  int n;
  cin >> n;
  vector<int> v(n, 0);
  int sum = 0;
  int res = INT_MAX;
  vector<int> tmp(n, 0);
  map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    // sum += abs(v[i] - (i+1));
    tmp[i] = v[i] - (i+1);
    mp[tmp[i]] = 0;
  }
  sort(all(v));
  sort(all(tmp));


  for(int i : tmp)
  {
    mp[i]++;
  }

  int median = tmp[n / 2];
  for(auto a : mp)
  {
    sum += abs(a.first - median) * a.second;
  }
  res = min(res, sum);
  // cout << res << endl;
  sum = 0;

  median = (tmp[n/2-1] + tmp[n/2]) / 2;
  for(auto a : mp)
  {
    sum += abs(a.first - median) * a.second;
  }
  res = min(res, sum);
  // cout << res << endl;
  sum = 0;

  median = (tmp[n/2-1] + tmp[n/2]) / 2 + 1;
  for(auto a : mp)
  {
    sum += abs(a.first - median) * a.second;
  }
  res = min(res, sum);
  // cout << res << endl;
  sum = 0;


  // for (int i = tmp[n/2-1]; i <= tmp[n/2]; i++)
  // {
  //   for(auto a : mp)
  //   {
  //     sum += abs(a.first - i) * a.second;
  //   }
  //   // cout << sum << endl;
  //   res = min(res, sum);
  //   sum = 0;
  // }

  // for(auto a : mp)
  // {
  //   sum += abs(a.first - median) * a.second;
  // }
  // int res = min(res, sum);

  cout << res << endl;
  // for(auto a : mp) sum += abs(a.first * a.second);


  // for(auto a : mp)
  // {
  //   cout << a.first << " : " << a.second << endl;
  // }
  //

}
