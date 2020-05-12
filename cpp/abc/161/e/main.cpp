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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, c;
  string s;
  cin >> n >> k >> c >> s;
  vector<int> v1(n, -1), v2(n, -1);
  int count = 1;
  for (int i = 0; i < int(s.size()); ++i) {
    if(s[i] == 'x') continue;
    v1[i] = count;
    count++;
    if(count == k+1) break;
    i += c;
  }

  // count = 1;
  count--;
  for (int i = int(s.size()) - 1; i >= 0; i--) {
    if(s[i] == 'x') continue;
    v2[i] = count;
    count--;
    if(count == 0) break;
    i -= c;
  }
  // print(v1);
  // print(v2);
  for (int i = 0; i < int(s.size()); ++i) {
    if(v1[i] == -1) continue;
    if(v1[i] == v2[i]) cout << i + 1 << endl;
  }
}
