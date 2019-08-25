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
  int n, m;
  cin >> n >> m;
  vector<p> v(m);
  vector<set<int>> rel(n);
  rep(i, m){
    cin >> v[i].first >> v[i].second;
    v[i].first--; v[i].second--;
    rel[v[i].first].insert(v[i].second);
    rel[v[i].second].insert(v[i].first);
  }

  for (int i = 0; i < n; i++) {
    set<int> friends = rel[i];
    set<int> fof;
    for(auto a : friends){
      for(auto b : rel[a]){
        if(rel[i].count(b) == 0 && i != b) fof.insert(b);
      }
    }
    cout << fof.size() << endl;
  }

}
