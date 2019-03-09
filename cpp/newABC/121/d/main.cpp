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

ll calc(ll a){
  ll ans = (a+1)/2;
  ans %= 2;
  if(a % 2 == 0) ans ^= a;
  return ans;
}

int main(){
  ll a, b;
  cin >> a >> b;
  cout << (calc(a-1) ^ calc(b)) << endl;
}
