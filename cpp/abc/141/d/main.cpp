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
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  priority_queue<int> q;
  rep(i, n){
    cin >> v[i];
    q.push(v[i]);
  }
  rep(i, m){
    int tmp = q.top();
    q.pop();
    tmp /= 2;
    q.push(tmp);
  }
  ll sum = 0;
  while(!q.empty()){
    sum += q.top();
    q.pop();
  }
  cout << sum << endl;
}
