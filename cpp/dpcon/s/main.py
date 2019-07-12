import sys
sys.setrecursionlimit(10 ** 6 + 100)

n = '30'
d = 4
dp = [[0] * 15 for i in range(10 ** 6 + 100)]


def dfs(k, now):
    print(k, now)
    if k != 0 and k % d == 0:
    for i in range(10):
        res += dfs(k+i, now+1)

    return res


print(dfs(0, 0))
