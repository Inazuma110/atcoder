#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> kukan;
  vector<char> status_v;
  int count = 1;
  for (int i = 0; i < n; i++) {
    int status = s[i];
    if(status == s[i+1]) count++;
    else if(i == n-2){
      kukan.push_back(count);
      status_v.push_back(status);
      count = 1;
    }
    else {
      kukan.push_back(count);
      status_v.push_back(status);
      count = 1;
    }
  }

  int num = int(kukan.size());

  count = 0;
  int res = -1;
  int res_count = 0;
  int begin = 0;
  for (int i = 0; i < num; i++) {
    // cout << i << endl;
    if(count < k){
      if(status_v[i] == '0') {
        count++;
      }
      res_count += kukan[i];
    }

    if(begin-1 >= 0 && status_v[begin-1] == '1'){
      res_count += kukan[begin-1];
    }
    if(i+1 < num && status_v[i+1] == '1'){
      res_count += kukan[i+1];
    }


    res = max(res_count, res);

    if(begin-1 >= 0 && status_v[begin-1] == '1'){
      res_count -= kukan[begin-1];
    }
    if(i+1 < num && status_v[i+1] == '1'){
      res_count -= kukan[i+1];
    }

    if(count == k && i+1 < num){
      res_count -= kukan[begin];
      if(status_v[begin] == '0') count--;
      else i--;
      begin++;
    }
    // }


  }

  cout << res << endl;

}
