#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

int main(){
  int n, c;
  cin >> n >> c;
  map<int, vector<p>> mp;

  for (int i = 0; i < n; i++) {
    int start, goal, ch;
    cin >> start >> goal >> ch;
    mp[ch].push_back({start, goal});
  }

  for (int i = 1; i <= c; i++) {
    sort(all(mp[i]));
  }

  int now = 1;
  map<int, int> use;
  int res = 0;
  bool isLoop = true;
  int no_use = 0;
  map<int, int> num;

  while(isLoop) {
    if(now > 100000) break;

    for (int i = 1; i <= c; i++) {
      if(use[i] == now) {
        no_use++;
        use[i] = 0;
      }
    }


    for (int i = 1; i <= c; i++) {
      if(num[i] >= int(mp[i].size())) continue;
      int start = mp[i][num[i]].first;
      // int goal = mp[i][num[i]].second;


      if(start == now){
        for (int j = num[i]; j < int(mp[i].size()); j++) {
          use[i] = mp[i][num[i]].second + 1;
          num[i] = j + 1;
          if(j == int(mp[i].size()) - 1) break;
          if(use[i]-1 != mp[i][num[i]].first) break;
        }
        if(no_use > 0) {
          no_use--;
        }else{
          res++;
        }
      }
    }

    isLoop = false;
    for (int i = 1; i <= c; i++) {
      if(int(mp[i].size()) > num[i]) {
        isLoop = true;
        break;
      }
    }
    now++;
  }

  cout << res << endl;
}
