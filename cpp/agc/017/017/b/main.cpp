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
  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  for (int i = 0; i < n-1; i++) {
    ll minv = i * c - (n-1-i)*d;
    ll maxv = i * d - (n-1-i)*c;
    if(b-a >= minv && b-a <= maxv){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;

}
