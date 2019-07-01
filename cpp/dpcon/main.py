from tail_recursion import tail_recursive
import sys
# 値メモ用のリストを-1で初期化
# リストの中身が-1のときは、まだ計算していないことを表す
dp = [-1] * (10**7 + 100)
dp[1] = 0
dp[2] = 0
dp[3] = 1
sys.setrecursionlimit(10 ** 7+100)

@tail_recursive
def trib(n):
    if not(dp[n] == -1):
        return dp[n]
    else:
        dp[n] = (trib(n-1) + trib(n-2) + trib(n-3)) % 10007
        return dp[n]


x = int(input())
print(trib(x))
