import sys

a = 0
e = 0
s = 0
r = 0


def dfs(s1, s2):
    global a, e, s, r
    if not s1:
        return len(s2) * min(a, e)
    if not s2:
        return len(s1) * min(a, e)

    if s1[0] == s2[0]:
        return dfs(s1[1:], s2[1:])

    c1 = dfs(s1, s2[1:]) * a
    c2 = dfs(s1[1:], s2) * e
    c3 = dfs(s1[1:], s2[1:]) * s
    print((c1))
    print((c2))
    print((c3))


    return min(c1, c2, c3)


def solve():
    global a, e, s, r
    x = (input())
    if x == '#':
        sys.exit(0)
    y = (input())
    a = int(input())
    e = int(input())
    s = int(input())
    r = int(input())
    print(dfs(x, y))


def main():
    while True:
        solve()


main()
