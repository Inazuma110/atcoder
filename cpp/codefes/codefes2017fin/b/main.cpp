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
  string s;
  cin >> s;
  map<char, int> mp;
  int n = int(s.size());
  if(n == 1){
    cout << "YES" << endl;
    return 0;
  }

  for(char c : s){
    mp[c]++;
  }
  if(mp.size() == 2 && n != 2){
    cout << "NO" << endl;
    return 0;
  }
  if(mp.size() == 1){
    cout << "NO" << endl;
    return 0;
  }

  int maxv = -1;
  int next = -1;

  for(auto a : mp){
    if(a.second >= maxv){
      maxv = a.second;
    }
  }
  for(auto a : mp){
    if(a.second >= next && a.second < maxv){
      next = a.second;
    }
  }
  int count = n - next - maxv;

  maxv -= count;
  next -= count;
  if(maxv >= 3){
    cout << "NO" << endl;
  }else if(next >= 2 || maxv >= 2){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
}
