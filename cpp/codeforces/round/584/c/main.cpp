#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

typedef long long ll;
typedef pair<ll, ll> p;

void solve(){
  int n;
  string s;
  cin >> n >> s;
  if(n == 1){
    cout << 1 << endl;
    return;
  }

  vector<int> tmp1(1, int(s[0]));
  vector<int> tmp2;
  vector<int> tmp1i(1, 0);
  vector<int> tmp2i;
  vector<int> res(n);

  for (int i = 1; i < n; i++) {
    int t1 = int(tmp1.size());
    int t2 = int(tmp2.size());
    if(tmp1[t1-1] >= int(s[i])){
      tmp1.push_back(int(s[i]));
      tmp1i.push_back(i);
    }else if(tmp2.empty() || tmp2[t2-1] >= int(s[i])){
      tmp2.push_back(int(s[i]));
      tmp2i.push_back(i);
    }else{
      cout << '-' << endl;
      return;
    }
  }

  if(tmp1[0] < tmp2[0]){
    for(auto a : tmp1i) res[a] = 1;
    for(auto a : tmp2i) res[a] = 2;
  }else{
    for(auto a : tmp1i) res[a] = 2;
    for(auto a : tmp2i) res[a] = 1;
  }
  rep(i, n) cout << res[i];
  cout << endl;
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  }
}
