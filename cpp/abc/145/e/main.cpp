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

int n, W;
int weight[5000], value[5000]; // 品物の個数は 100 個なので少し余裕持たせてサイズ 110 に

// DPテーブル
int dp[5000][5000] = {0}; // テーブルの初期値はすべて 0 にしておきます

// 復元用テーブル
int prev_w[5000][5000];

int main() {
  // 入力受け取り
  cin >> n >> W;
  for (int i = 0; i < n; ++i) cin >> weight[i] >> value[i];
  vector<pair<p, int>> tmp(n);
  for (int i = 0; i < n; i++) {
    tmp[i] = {{value[i], weight[i]}, i};
  }

  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      // i 番目の品物を選ぶ場合を考える
      if (w >= weight[i]) {
        if (dp[i+1][w] < dp[i][w-weight[i]] + value[i]) {
          dp[i+1][w] = dp[i][w-weight[i]] + value[i];
          prev_w[i+1][w] = w - weight[i];
        }
      }

      if (dp[i+1][w] < dp[i][w]) {
        dp[i+1][w] = dp[i][w];
        prev_w[i+1][w] = w;
      }
    }
  }

  // 最適値の出力
  // cout << dp[n][W-1] << endl;


  int cur_w = W-1;
  vector<int> used;
  for (int i = n-1; i >= 0; --i) {
    if (prev_w[i+1][cur_w] == cur_w - weight[i]) {
      used.push_back(i);

      // cout << i << " th item (weight = " << weight[i] << ", value = " << value[i] << ")" << endl;
    }

    // 復元テーブルをたどる
    cur_w = prev_w[i+1][cur_w];
  }
  ll res = dp[n][W-1];
  sort(RALL(tmp));

  for (int i = 0; i < n; i++) {
    bool flag = true;
    for(auto a : used){
      if(a == tmp[i].second){
        flag = false;
        break;
      }
    }
    if(flag){
      res += tmp[i].first.first;
      break;
    }
  }
  cout << res << endl;


}
