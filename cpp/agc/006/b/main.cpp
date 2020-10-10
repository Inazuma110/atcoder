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
  int n, x;
  cin >> n >> x;
  if(2 * n - 1 == x || x == 1){
    cout << "No" << endl;
    return 0;
  }

  map<int, int> mp;
  map<int, bool> use;

  mp[n] = x;
  use[x] = true;
  use[x-1] = true;
  use[x+1] = true;
  if(x > 2){
    mp[n-1] = x+1;
    mp[n+1] = x-1;
    mp[n-2] = x-2;
    use[x-2] = true;
  }else{
    mp[n-1] = x+1;
    mp[n+1] = x-1;
    mp[n+2] = x+2;
    use[x+2] = true;
  }
  // print(use);

  vector<int> tmp;
  int skip1 = 1;
  // int skip2 = 0;
  cout << "Yes" << endl;
  for (int i = 1; i <= 2*n-1; i++) {
    if(mp[i] != 0) {
      cout << mp[i] << endl;
      use[mp[i]] = true;
      // tmp.push_back(i);
    } else {
      if(!use[i]){
        use[i] = true;
        cout << i << endl;
      }else{
        for (int j = skip1; j <= 2*n-1; j++) {
          if(!use[j]){
            cout << j << endl;
            use[j] = true;
            skip1 = j;
            break;
          }
        }
        // print(tmp);
        // cout << skip1 << endl;
        // if(int(tmp.size()) > skip1 && !use[tmp[skip1]]){
        //   cout << tmp[skip1] << endl;
        //   use[tmp[skip1]] = true;
        //   skip1++;
        // }else{
        //   cout << 2*n-1 - skip2 << endl;
        //   use[2*n-1 - skip2] = true;
        //   skip2++;
        // }
      }
    }

  }
}
