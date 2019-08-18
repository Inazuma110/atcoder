n, k = map(int, input().split())
s = input()

for num, i in enumerate(s):
    if num == k-1:
        print(i.lower(), end='')
    else:
        print(i, end='')
print()

