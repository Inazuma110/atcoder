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
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  int r, c, k;
  cin >> r >> c >> k;
  int n;
  cin >> n;
  vector<p> v(n);
  vector<int> score_y(r);
  vector<int> score_x(c);
  rep(i, n){
    cin >> v[i].first >> v[i].second;
    v[i].first--;v[i].second--;
    score_y[v[i].first]++;
    score_x[v[i].second]++;
  }
  ll res = 0;
  map<int, int> r_num;
  for(auto a : score_y) r_num[a]++;
  map<int, int> c_num;
  for(auto a : score_x) c_num[a]++;

  rep(i, k+1){
    res += r_num[i] * c_num[k - i];
  }
  // for(auto a : r_num){
  //   res += a.second * c_num[k - a.first];
  // }
  // print(score_y);
  // print(score_x);
  // print(r_num);
  // print(c_num);


  for(auto a : v){
    int i = a.first;
    int j = a.second;
    if(score_y[i] + score_x[j] == k) res--;
    if(score_y[i] + score_x[j] == k+1) res++;
  }

  cout << res << endl;

}
