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
  ll n, a, b;
  cin >> n >> a >> b;
  if(a > b || (n == 1 && a != b)){
    cout << 0 << endl;
    return 0;
  }else if(a==b){
    cout << 1 << endl;
    return 0;
  }
  ll res = a + b;
  cout << res + b * (n-2) - (res + a * (n-2)) + 1 << endl;
}
