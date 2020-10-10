#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1000000007
#define INF 100100100

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ll n;
  cin >> n;
  set<int> s;
  // s.insert(-1);
  // s.insert(n);
  //
  // val, place
  vector<p> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(all(v));
  ll res = 0;


  // print(v);
  for (int i = 0; i < n; i++) {
    s.insert(v[i].second);
    auto a = lower_bound(all(s), v[i].second);
    int left, right;

    if(a == s.begin()){
      left = v[i].second+1;
    }else{
      auto
    }
    if(a == s.end()){
      right = n - v[i].second;
    }
    cout << *a << endl;
    print(s);
  }

  cout << res << endl;

}
