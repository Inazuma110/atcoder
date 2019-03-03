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
  int a, b, k;
  cin >> a >> b >> k;
  int count = 0;
  for (int i = 100; i >= 1; i--) {
    if(a % i == 0 && b % i == 0){
      count++;
      if(count == k){
        cout << i << endl;
        return 0;
      }
    }
  }
}

