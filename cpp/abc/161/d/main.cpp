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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;

vector<ll> g;
int c = 0;
int k;

// void dfs(int i, string num){
//   g.push_back(num);
//   c++;
//   if(c == k) return;
//   int n = int(num.size());
//   for(int j = 0; j <= 9; j++) {
//     int l = stoi(num.substr(n-1, 1));
//     if(c == k) return;
//     if(abs(l - j) > 1) continue;
//     else dfs(i+1, num + to_string(j));
//   }
// }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k;
  if(k <= 9){
    cout << k << endl;
    return 0;
  }

  priority_queue<ll, vector<ll>, function<bool(ll,ll)>>q(
      [](ll a,ll b){return a>b;}
      );
  for (int i = 1; i < 10; ++i) {
    q.push((i));
  }
  c = 9;

  while(!q.empty() && c <= k){
    string v = to_string(q.top());
    // cout << v << endl;
    q.pop();
    int n = int(v.size());
    for(ll i = 0; i <= 9; i++){
      ll l = stoi(v.substr(n-1));
      if(abs(l - i) > 1) continue;
      q.push(stoll(v + to_string(i)));
      c++;
      if(c == k) {
        cout << v+to_string(i) << endl;
        return 0;
      }
    }
  }

  // cout << g[k-1] << endl;

}
