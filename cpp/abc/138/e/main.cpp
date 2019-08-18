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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  map<char, vector<int>> mp;
  map<char, set<int>> mp2;

  for (int i = 0; i < int(s.size()); i++) {
    mp2[s[i]].insert(i);
  }
  for(auto a : mp2){
    mp[a.first] = vector<int> (ALL(a.second));
  }

  if(mp[t[0]].size() == 0){
    cout << -1 << endl;
    return 0;
  }

  int before = *min_element(ALL(mp[t[0]]));
  ll res = 0;

  for (int i = 1; i < int(t.size()) - 1; i++) {
    if(mp[t[i]].size() == 0){
      cout << -1 << endl;
      return 0;
    }

    int index = upper_bound(ALL(mp[t[i]]), before) - mp[t[i]].begin();
    // cout << index << endl;
    if(index >= mp[t[i]].size()){
      before = mp[t[i]][0];
      res++;
    }
    else before = mp[t[i]][index];
  }

  res = res * int(s.size()) + before + 1;


  int n = int(t.size());
  if(mp[t[n-1]].size() == 0){
    cout << -1 << endl;
    return 0;
  }

  int m = int(s.size());
  if(n > 1){
    while(true){
      before++;
      res++;
      if(s[before % m] == t[n-1]){
        break;
      }
    }

  }

  cout << res << endl;
}
