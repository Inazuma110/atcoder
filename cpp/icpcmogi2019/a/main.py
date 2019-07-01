import sys


def solve():
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        sys.exit(0)
    a = list(map(int, input().split()))

    res = 0
    for i in a:
        res += min(i, m//n)
    return res


def main():
    while True:
        print(solve())


main()
