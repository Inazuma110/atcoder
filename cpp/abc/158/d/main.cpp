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
  string s;
  int q;
  cin >> s >> q;

  deque<char> d;
  for(char c : s) d.push_back(c);
  string buf1 = "", buf2 = "";
  bool is_rev = false;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if(t==1){
      is_rev = !is_rev;
    } else{
      int f1;
      char c;
      cin >> f1 >> c;
      if(!is_rev){
        if(f1 == 1) d.push_front(c);
        else d.push_back(c);
      }else{
        if(f1 == 1) d.push_back(c);
        else d.push_front(c);
      }
    }
  }

  if(!is_rev){
    while(!d.empty()){
      cout << d.front();
      d.pop_front();
    }
  }else{
    while(!d.empty()){
      cout << d.back();
      d.pop_back();
    }
  }
  cout << endl;
}
