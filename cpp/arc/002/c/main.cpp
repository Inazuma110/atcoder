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

string buttons[] = {"A", "B", "X", "Y"};
int n;
string s;

int f(string com1, string com2){
  int used = 0;
  for (int i = 0; i < n-1; ++i) {
    string tmp = s.substr(i, 2);
    if(tmp == com1 || tmp == com2){
      used++;
      i++;
    }
  }
  return used;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;

  int used = -1;
  for(auto b1 : buttons){
    for(auto b2 : buttons){
      for(auto b3 : buttons){
        for(auto b4 : buttons){
          string com1 = b1 + b2;
          string com2 = b3 + b4;
          if(com1 == com2) continue;
          chmax(used, f(com1, com2));
        }
      }
    }
  }

  cout << n - used << endl;
}
