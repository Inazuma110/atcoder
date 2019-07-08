import sys


def solve(g,  y,  m,  d):
    y = int(y)
    m = int(m)
    d = int(d)

    if y == 31 and m >= 5:
        print('?', y-30, m, d)
    elif y >= 32:
        print('?', y-30, m, d)
    else:
        print(g, y, m, d)


while True:
    s = input()
    if s == "#":
        break
    solve(*map(str,  s.split()))
