import sys
n, m = map(int, input().split())
s = [0 for i in range(m)]
c = [0 for i in range(m)]

for i in range(m):
    s[i], c[i] = map(int, input().split())

for i in range(1, 10000):
    if len(str(i)) != n:
        continue
    flag = True
    for j, k in zip(s, c):
        j -= 1
        if int(str(i)[j]) != (k):
            flag = False
            break
        # print(j, k)
    if flag:
        print(i)
        sys.exit(0)

print(-1)
