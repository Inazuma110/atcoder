#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
// #include <atcoder/all>

using boost::multiprecision::cpp_int;
using namespace std;
// using namespace atcoder;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;
int n;

bool check(vector<p> v){
  rep(i, n) if(v[i].second < v[i].first) return false;
  for (int i = 1; i < n; ++i) {
    if(v[i].first < v[i-1].first) return false;
    if(v[i].second < v[i-1].second) return false;
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<p> v(n);
  vector<int> used(2*n+1);
  priority_queue<p> pq;
  bool flag = false;
  rep(i, n){
    cin >> v[i].first >> v[i].second;
    if(v[i].first != -1) used[v[i].first]++;
    if(v[i].second != -1) used[v[i].second]++;
    if(v[i].second != -1 && v[i].second < v[i].first) flag = true;
    pq.push({v[i].first, i});
    pq.push({v[i].second, i});
  }


  for (int i = 1; i < 2*n+1; ++i) {
    bool flag2 = false;
    auto tmpv = v;
    auto used2 = used;
    rep(j, n){
      if(tmpv[j].second != -1 && tmpv[j].first != -1 && tmpv[j].second - tmpv[j].first-1 == i){
        flag2 = true;
        break;
      }else{
        if(tmpv[j].first == -1 && tmpv[j].second == -1) continue;
        else if(tmpv[j].first == -1) {
          ll next = tmpv[j].second - i-1;
          if(next < 1 || next > 2*n) {
            flag2 = true;
            break;
          }
          if(used2[next]){
            flag2 = true;
            break;
          }else{
            used2[next] = true;
            tmpv[j].first = next;
          }
        }else if(tmpv[j].second == -1){
          ll next = i+tmpv[j].first+1;
          if(next < 1 || next > 2*n) {
            flag2 = true;
            break;
          }
          if(used2[next]){
            flag2 = true;
            break;
          }else{
            used2[next] = true;
            tmpv[j].second = next;
          }
        }
      }
    }
    if(flag2) continue;


    int count = 1;
    rep(j, n){
      if(v[j].first != -1 || v[j].second != -1) continue;
      while(1){
        if(used2[count]) {
          count++;
          continue;
        }

        v[i].first = count;
        ll next = i+v[i].first+1;
        if(next < 1 || next > 2*n) {
          flag2 = true;
          break;
        }
        if(used2[count]){
          flag2 = true;
          break;
        }else{
          v[j].second = next;
          used2[next]++;
          break;
        }
      }
      if(flag2) break;
    }


    rep(j, 2*n+1){
      if(used2[j] >= 2) flag2 = true;
    }
    if(flag2) continue;
    auto is_valid = check(tmpv);

    if(is_valid) {
      cout << "Yes" << endl;
      exit(0);
    }
  }

  cout << "No" << endl;

  // int now = 2*n;
  // while(!pq.empty()){
  //   int idx = pq.top().second;
  //   pq.pop();
  //   if(v[idx].first == -1){
  //     while(1){
  //       if(!used[now]){
  //         v[idx].first = now;
  //         now--;
  //         break;
  //       }
  //       now--;
  //     }
  //   }
  //
  //   if(v[idx].second == -1){
  //     while(1){
  //       if(!used[now]){
  //         v[idx].second = now;
  //         now--;
  //         break;
  //       }
  //       now--;
  //     }
  //   }
  // }
  //
  // sort(ALL(v));
  // for (int i = 1; i < n; ++i) {
  //   if(v[i].first < v[i-1].first) flag = true;
  //   if(v[i].second < v[i-1].second) flag = true;
  // }
  // rep(i, 2*n+1){
  //   if(used[i] >= 2) flag = true;
  // }
  //
  // rep(i, n) if(v[i].second < v[i].first) flag = true;

  // if(flag) cout << "No" << endl;
  // else cout << "Yes" << endl;

}
