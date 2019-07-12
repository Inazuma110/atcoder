import sys
sys.setrecursionlimit(10**8)

M = 10**9 + 7
K = int(input())
D = int(input())

dp = [[None] * 100 for _ in range(10**5 + 1)]
def f(k, i):
    if dp[i][k] is not None:
        return dp[i][k]

    if i == 0:
        r = (k % D) == 0
        dp[i][k] = r
        return r
    r = sum(f((k + x) % D, i - 1) for x in range(0, 10)) % M
    dp[i][k] = r
    return r

# dp = [[0] * 100 for _ in range(10**5 + 1)]
# for i in range(10**5 + 1):
#     for k in range(100):
#         if i == 0:
#             dp[i][k] = int((k % D) == 0)
#         else:
#             dp[i][k] = sum(dp[(k + x) % D][i - 1] for x in range(0, 10)) % M
#
# def f(k, i):
#     return dp[i][k]

sk = str(K)
dig = len(sk)
answer = 0
s = sum(map(int, list(sk)))
for j in range(int(sk[-1]) + 1):
    if (s - j) % D == 0:
        answer += 1
        answer %= M

if dig > 1:
    s -= int(sk[-1])
    for i in range(dig - 1, 1, -1):
        if sk[i - 1] == "0":
            continue
        for j in range(int(sk[i - 1])):
            answer += f((s - 1) % D - j, dig - i) % M
        s -= int(sk[i - 1])

    for k in range(1, int(sk[0])):
        answer += f(k % D, dig - 1) % M

    if dig > 1: # 先頭0固定
        for k in range(10):
            answer += f(k % D, dig - 2) % M


print(dp[:100])
print((answer - 1) % M)
