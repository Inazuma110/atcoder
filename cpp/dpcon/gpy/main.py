import sys
sys.setrecursionlimit(10 ** 6 + 100)
n, m = map(int, input().split())

memo = [-1] * (10 ** 6 + 100)

g = [[] for i in range(n + 1)]

for i in range(m):
    x, y = map(int, input().split())
    g[y].append(x)


def dfs(i):
    if memo[i] != -1:
        return memo[i]
    if not g[i]:
        return 0
    else:
        memo[i] = max(dfs(v) for v in g[i]) + 1
        return memo[i]


for i in range(1, n+1):
    dfs(i)

print(max(memo))
