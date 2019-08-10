w, h = map(int, input().split())
MOD = 1000000007


def comb(n, r):
    if r > n - r:
        r = n - r

    ans = 1
    for i in range(1, r + 1):
        ans *= n - r + i
        ans %= MOD
        ans //= i

    return ans


w -= 1
h -= 1
print(comb(w + h, w) % MOD)

