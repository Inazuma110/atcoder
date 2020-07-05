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
int d;
vector<ll> c(26);
vector<vector<ll>> s;
vector<ll> t;
vector<p> q;
vector<ll> sche;
ll res = 0;
vector<vector<ll>> last;

ll score_plus(ll day, ll contest){
  return s[day-1][contest-1];
}

void update_last(ll day, ll contest){
  if(day != 0) last[day] = last[day-1];
  last[day][contest-1] = day;
}

ll minous_score(ll day, ll contest){
  ll tmp = c[contest-1] * (day - last[day][contest-1]);
  return tmp;
}

ll score(ll day){
  ll tmp = score_plus(day, sche[day-1]);

  rep(contest, 26){
    tmp -= minous_score(day, contest+1);
  }
  return tmp;
}

ll update_score(ll day, ll contest){
  ll tmp = 0;
  int from = sche[day-1];

  tmp += score_plus(day, contest);
  tmp -= score_plus(day, from);

  tmp -= c[from-1] * (d-day+1);
  tmp += c[contest-1] * (d-day+1);

  // print(last);
  for (int i = day; i <= d; ++i) {
    last[i][from-1]--;
    last[i][contest-1]++;
  }
  sche[day-1] = contest;

  // print(last);
  cout << tmp << endl;
  return tmp;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> d;
  rep(i, 26) cin >> c[i];
  s = vector<vector<ll>> (d, vector<ll>(26));
  sche = vector<ll> (d);
  for (int i = 0; i < d; ++i) {
    ll maxv = LLONG_MIN;
    ll contest = -1;
    for (int j = 0; j < 26; ++j) {
      cin >> s[i][j];
      if(maxv < s[i][j]){
        maxv = s[i][j];
        contest = j + 1;
      }
    }

    sche[i] = contest;
    // cout << contest << endl;
  }
  t = vector<ll> (d);
  rep(i, d) cin >> t[i], t[i]--;
  last = vector<vector<ll>> (d+1, vector<ll>(26));

  ll now = 0;
  rep(i, d){
    update_last(i+1, sche[i]);
    now += score(i+1);
    cout << now << endl;
  }
  cout << "----" << endl;

  // print(sche);
  // print(t);

  int m;
  cin >> m;
  q = vector<p>(m);


  rep(i, m){
    cin >> q[i].first >> q[i].second;
    // sche[q[i].first] = q[i].second;
    now += update_score(q[i].first, q[i].second);
    // cout << now << endl;
  }



  // score();
  // cout << score() << endl;
}
