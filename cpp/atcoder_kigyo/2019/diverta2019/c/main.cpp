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

int counter(string s){
  int n = int(s.size());
  int count = 0;
  for (int i = 1; i < n; i++) {
    if(s[i] == 'B' && s[i-1] == 'A') {
      count++;
    }
  }
  return count;
}

bool last_a(string s){
  int n = int(s.size());
  if(s[n-1] == 'A') return true;
  else return false;
}

int first_b(string s){
  if(s[0] == 'B') return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> v(n+2, "X");
  vector<int> count(n+2);
  vector<bool> count_a(n+2, false);
  vector<bool> count_b(n+2, false);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    count[i] = counter(v[i]);
    count_a[i] = last_a(v[i]);
    count_b[i] = first_b(v[i]);
  }
  ll res = 0;

  int tmp1 = 0;
  int tmp2 = 0;
  int tmp3 = 0;
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    if(count_b[i] && count_a[i]){
      if(flag){
        res++;
      }
      tmp3++;
      flag = true;
      continue;
    }
    if(count_a[i]) tmp1++;
    else if(count_b[i]) tmp2++;
  }
  // cout << res << endl;

  if(flag && tmp1 > 0){
    res++;
    tmp1--;
  }
  if(tmp2 > 0 && flag){
    res++;
    tmp2--;
  }
  // cout << res << endl;


  res += min(tmp1, tmp2);
  // cout << res << endl;

  for (int i = 1; i <= n+1; i++) {
    res += count[i];
  }

  cout << res << endl;
}
