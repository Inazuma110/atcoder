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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<p> v(q);
  for (int i = 0; i < q; i++) {
    cin >> v[i].first >> v[i].second;
  }
  vector<int> sum(n, 0);
  bool flag = false;
  int count = 0;
  for (int i = 0; i < n; i++){
    if(flag && s[i] == 'C'){
      flag = false;
      count++;
    }else if(s[i] == 'A'){
      flag = true;
    }else{
      flag = false;
    }
    sum[i] = count;
  }

  for (int i = 0; i < q; i++) {
    int l = v[i].first - 1;
    int r = v[i].second - 1;
    cout << sum[r] - sum[l] << endl;
  }
}
