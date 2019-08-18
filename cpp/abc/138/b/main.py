n = int(input())
a = list(map(int, input().split()))

res = 0
for i in a:
    res += (1 / i)

res = 1 / res

print(res)
