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
  long double deg, dis;
  cin >> deg >> dis;
  deg /= 10.0;
  dis /= 60;
  dis *= 10;
  dis = round(dis);
  dis /= 10;

  if(dis <= 0.2){
    cout << 'C' << ' ' << 0 << endl;
    return 0;
  }

  vector<string> a = {"N", "NNE",  "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};

  bool flag = true;
  for (int i = 0; i < 16; i++) {
    long double minv = 11.25 + double(i) * 22.5;
    if(deg >= minv && deg < minv + 22.5){
      flag = false;
      cout << a[i+1] << ' ';
      break;
    }
  }
  if(flag) cout << "N ";

  vector<long double> b = {0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6};

  for(int i = 0; i < int(b.size()); i++){
    // b[i] *= 10;
    // b[i] = round(b[i]);
    // b[i] /= 10;
    b[i] += 0.00001;
    // b[i] *= 60.0;
  }

  flag = true;
  for (int i = 0; i < int(b.size()); i++) {
    if(dis <= b[i]){
      cout << i << endl;
      flag = false;
      break;
    }
  }

  if(flag){
    cout << 12 << endl;
  }

}

