def rec(depth, s):
    if depth == -1:
        result.append(s)
        return
    rec(depth-1, s-W[depth])
    rec(depth-1, s)
    rec(depth-1, s+W[depth])

while True:
    n, m = map(int, input().split())
    if n == m == 0:
        break
    A = list(map(int, input().split()))
    W = list(map(int, input().split()))
    result = []
    rec(len(W)-1, 0)
    ad = []
    cnt = 0
    for a in A:
        if not (a in result):
            cnt += 1
            adi = [abs(a-r) for r in result]
            ad.append(adi)
    if cnt == 0:
        print(0)
    else:
        adset = set(ad[0])
        for i in range(1, len(ad)):
            adset = adset & set(ad[i])
        if len(adset) != 0:
            print(min(adset))
        else:
            print(-1)
    

    # print(ad)
    # print(n, m, A, W)
