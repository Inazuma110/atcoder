#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;

int n, k;
vector<p> v;
ll dsum = 0;
ll ksum = 0;
map<int, bool> mp;
int selected = 0;
int kcount = 0;

int main(){
  cin >> n >> k;
  kcount = k;
  for (int i = 0; i < n; i++) {
    int tmp1;
    int tmp2;
    cin >> tmp2 >> tmp1;
    v.push_back({tmp1, tmp2});
  }
  sort(rall(v));

  while(kcount >= 0 && selected < k) {
    int size = int(v.size());
    for (int i = 0; i < size; i++) {
      if(selected == k) break;
      int d = v[i].first;
      int ktmp = v[i].second;
      if(!mp[ktmp]){
        dsum += d;
        mp[ktmp] = true;
        ksum++;
        selected++;
        v.erase(v.begin() + i);
        i--;
      }
      else if(d > kcount * kcount){
        dsum += d;
        selected++;
        v.erase(v.begin() + i);
        i--;
      }
      print(mp);
      print(v);
    }
    kcount--;
  }

  cout << dsum << endl;
  cout << ksum << endl;

  cout << dsum + int(mp.size() * mp.size()) << endl;
}
