n = int(input())
a = list(map(int, input().split()))


res = 0
while len(a) > 1:
    index = -1
    sum_size = float('inf')
    n = len(a)
    for i in range(n-1):
        if sum_size > a[i] + a[i+1]:
            sum_size = a[i] + a[i+1]
            index = i

    a[index] = a[index] + a[index+1]
    res += a[index]
    a.pop(index+1)
    # print(res)


print(res)
