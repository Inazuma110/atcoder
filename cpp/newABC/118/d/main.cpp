#include <bits/stdc++.h>
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> p;
map<int, int> mp;
int n, m;
vector<int> v;

string res1 = "";

void mp_init(){
  mp[1] = 2;
  mp[2] = 5;
  mp[3] = 5;
  mp[4] = 4;
  mp[5] = 5;
  mp[6] = 6;
  mp[7] = 3;
  mp[8] = 7;
  mp[9] = 6;
}

string dp[2000];


string my_max(string s1, string s2){
  if(s1.size() > s2.size()) return s1;
  else if(s1.size() == s2.size()){
    if(s1 > s2) return s1;
    else return s2;
  }else return s2;
}

void my_search(){

}



int main(){
  mp_init();
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(rall(v));
  dfs(n, "", 0);

  cout << res1 << endl;
}
