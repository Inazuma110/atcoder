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
  int n;
  cin >> n;
  vector<pair<long double, long double>> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  double d = 0;
  sort(RALL(v));

  ll x = 0;
  ll y = 0;
  rep(i, n){
    ll nx = x + v[i].first;
    ll ny = y + v[i].second;
    if(sqrt(x * x + y * y) <= sqrt(nx * nx + ny * ny)){
      x = nx;
      y = ny;
    }
  }
  d = max(d, sqrt(x * x + y * y));
  x = 0, y = 0;
  sort(ALL(v));
  rep(i, n){
    ll nx = x + v[i].first;
    ll ny = y + v[i].second;
    if(sqrt(x * x + y * y) <= sqrt(nx * nx + ny * ny)){
      x = nx;
      y = ny;
    }
  }
  d = max(d, sqrt(x * x + y * y));


  rep(i, n){
    v[i].first *= -1;
  }
  sort(RALL(v));

  x = 0;
  y = 0;
  rep(i, n){
    ll nx = x + -v[i].first;
    ll ny = y + v[i].second;
    if(sqrt(x * x + y * y) <= sqrt(nx * nx + ny * ny)){
      x = nx;
      y = ny;
    }
  }
  d = max(d, sqrt(x * x + y * y));

  x = 0, y = 0;
  sort(ALL(v));
  rep(i, n){
    ll nx = x + -v[i].first;
    ll ny = y + v[i].second;
    if(sqrt(x * x + y * y) <= sqrt(nx * nx + ny * ny)){
      x = nx;
      y = ny;
    }
  }
  d = max(d, sqrt(x * x + y * y));

  rep(i, n){
    v[i].first *= -1;
  }

  rep(i, n){
    long double tmp = v[i].first;
    v[i].first = v[i].second;
    v[i].second = tmp;
  }

  sort(RALL(v));
  x = 0, y = 0;

  rep(i, n){
    ll nx = x + v[i].first;
    ll ny = y + v[i].second;
    if(sqrt(x * x + y * y) <= sqrt(nx * nx + ny * ny)){
      x = nx;
      y = ny;
    }
  }
  d = max(d, sqrt(x * x + y * y));

  sort(ALL(v));
  x = 0, y = 0;
  rep(i, n){
    ll nx = x + v[i].first;
    ll ny = y + v[i].second;
    if(sqrt(x * x + y * y) <= sqrt(nx * nx + ny * ny)){
      x = nx;
      y = ny;
    }
  }
  d = max(d, sqrt(x * x + y * y));

  rep(i, n){
    v[i].second*= -1;
  }

  sort(RALL(v));
  x = 0, y = 0;

  rep(i, n){
    ll nx = x + v[i].first;
    ll ny = y + v[i].second;
    if(sqrt(x * x + y * y) <= sqrt(nx * nx + ny * ny)){
      x = nx;
      y = ny;
    }
  }
  d = max(d, sqrt(x * x + y * y));

  sort(ALL(v));
  x = 0, y = 0;
  rep(i, n){
    ll nx = x + v[i].first;
    ll ny = y + v[i].second;
    if(sqrt(x * x + y * y) <= sqrt(nx * nx + ny * ny)){
      x = nx;
      y = ny;
    }
  }
  d = max(d, sqrt(x * x + y * y));


  rep(i, n){
    v[i].second*= -1;
  }

  cout<<setprecision(15);
  cout << d << endl;
}
