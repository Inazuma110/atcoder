n = int(input())
a = list(map(int, input().split()))

minv = a[0]
minvs = []

def f(x):
    global minv
    # global minvs
    minvs.append(min(minv, a[x]))
    minv = min(minv, a[x])


for i in range(n):
    f(i)

print(minvs)
