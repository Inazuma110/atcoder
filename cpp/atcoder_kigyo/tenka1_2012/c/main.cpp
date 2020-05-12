#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

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

bool is_mark(char c){
  return (c == 'S' || c == 'H' || c == 'D' || c == 'C');
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = int(s.size());
  vector<string> cards;
  string card = "";
  for (int i = 0; i < n; ++i) {
    if(is_mark(s[i])){
      cards.push_back(card);
      card = "";
    }
    card += s[i];
  }
  cards.erase(cards.begin());

  vector<vector<string>> tmp = {
    {"S10", "SJ", "SQ", "SK", "SA"},
    {"H10", "HJ", "HQ", "HK", "HA"},
    {"D10", "DJ", "DQ", "DK", "DA"},
    {"C10", "CJ", "CQ", "CK", "CA"}
  };


  int count = 0;
  map<string, int> mp;
  for(auto card : cards){
    mp[card]++;
    count++;
    for(auto mark : tmp){
      bool flag = true;
      for(auto x : mark){
        if(mp[x] <= 0) flag = false;
      }
      if(flag) {
        char mark_i = mark[0][0];
        if(count == 5){
          cout << 0 << endl;
          return 0;
        }
        for(int i = 0; i < count; i++){
          string card = cards[i];
          string num = card.substr(1);
          if(card[0] == mark_i && (num == "10" || num == "J" || num == "Q" || num == "K" || num == "A")){
            continue;
          }
          cout << card;
        }
        cout << endl;
        return 0;
      }
    }
  }
}
