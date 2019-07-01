import sys


def f(x, y):
    if x == 0 and y >= 3 and y % 2 == 1:
        return y + 1
    if x % 2 == 0 and y % 2 == 0:
        return x + y
    else:
        return x + y + 1


def solve(a, b):
    a = abs(a)
    b = abs(b)
    if a > b:
        a, b = b, a
    if (a == 1 and b == 1) or (a == 0 and b == 1) or (a == 1 and b == 0):
        return 1
    else:
        f(a, b)


def main():
    # try:
    #     while True:
    #         solve(*map(int,  input().split()))
    # except:
    #     pass
    for i in range(10):
        for j in range(10):
            res = solve(i, j)
            print(f'{res}\t', end='')
        print()


main()
