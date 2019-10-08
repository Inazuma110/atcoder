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


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, t, k;
  cin >> n >> m >> t >> k;
  vector<vector<tuple<int, int, int>>> v(n, vector<tuple<int, int, int>> ());
  for (int i = 0; i < m; i++) {
    int from, to, cost, traffic;
    cin >> from >> to >> cost >> traffic;
    from--; to--;
    v[from].push_back({to, cost, traffic});
    v[to].push_back({from, cost, traffic});
  }
  vector<ll> time(n, LLONG_MAX);
  time[0] = 0;
  queue<p> q;
  vector<bool> visited(n, false);
  visited[0] = true;
  for(auto a : v[0]){
    int tmp = 0;
    int traffic = get<2>(a) - t;
    if(traffic > k) tmp = traffic - k;
    cout << tmp << endl;
    time[get<0>(a)] = min(time[get<0>(a)], ll(get<1>(a) + tmp));
    q.push({ll(get<0>(a)), time[get<0>(a)]});
  }
  print(time);

  while(!q.empty()){
    ll from = q.front().first;
    ll now = q.front().second;
    q.pop();
    visited[from] = true;

    for(auto a : v[from]){
      if(!visited[get<0>(a)]){
        int tmp = 0;
        int traffic = get<2>(a) - abs(t - now);
        if(traffic > k) tmp = traffic - k;
        time[get<0>(a)] = min(time[get<0>(a)], ll(get<1>(a) + tmp + now));
        q.push({ll(get<0>(a)), ll(get<1>(a) + tmp + now)});
      }
    }
    print(time);
  }
  print(time);
}
