n = int(input())
b = list(map(int, input().split()))

ans = []
for _ in range(200):
    if len(b) == 0:
        for i in reversed(ans):
            print(i)
        break
    for i, v in enumerate(reversed(b)):
        if len(b)-i == v:
            ans.append(len(b)-i)
            del b[len(b)-i-1]
            break
    else:
        print(-1)
        break

