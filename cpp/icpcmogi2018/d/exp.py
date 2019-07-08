count = [0 for i in range(10)]
# for i in range(100001):
for i in range(100000):
    if len(set(str(i))) == 2:
        # print(i)
        count[len(str(i))] += 1
print(count)
ans = 0
for i in count:
    ans += i
    print(ans, end=' ')