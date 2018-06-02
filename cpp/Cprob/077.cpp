#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> p;


int main()
{
  int n;
  cin >> n;
  vector<int> a(n, 0);
  vector<int> b(n, 0);
  vector<int> c(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i] >> c[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());

  
  return 0;
}
