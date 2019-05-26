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
  int n;
  cin >> n;

  map<string, vector<p>> mp;
  for (int i = 0; i < n; i++) {
    string s;
    int point;
    cin >> s >> point;
    if(mp[s].size() == 0) mp[s] = vector<p> ();
    mp[s].push_back({point, i+1});
  }

  for(auto a : mp){
    auto x = mp[a.first];
    sort(RALL(x));
    // print(x);
    for(auto b : x){
      cout << b.second << endl;
    }
  }

}
