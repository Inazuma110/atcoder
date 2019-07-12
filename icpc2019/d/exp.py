
def rec(left, right, cnt):
    if left == right:
        return 0
    ret = INFTY
    maxcnt.append(cnt)
    for k in range(left, right):
        x = B[k]-A[k]-cnt
        while x < 0:
            x += m
        ret = min(ret, rec(left, k, cnt+x) + rec(k+1, right, cnt+x) + x)
    # print(left, right, ret)
    return ret
INFTY = float('inf')
while True:
    maxcnt = [0]
    n, m = map(int, input().split())
    # memo = [[[INFTY for j in range(n)]for i in range(n)] for ]
    if n == m:
        break
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    print(rec(0, n, 0))
    print(max(maxcnt))
    # print(rec(2, 4, 0))
