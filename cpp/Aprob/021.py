n = input()
nint = int(n)
res = 0
sum = 0

while True:
    for i in range(0,len(n)):
        sum += int(n[i])

    if res <= sum:
        res = sum




print(sum)
