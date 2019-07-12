while True:
    n, m = map(int, input().split())
    if n == m == 0:
        break
    ans = [0 for i in range(n)]
    for i in range(m):
        p = list(map(int, input().split()))
        for j in range(n):
            ans[j] += p[j]
    print(max(ans))