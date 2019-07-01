import sys


def f(a, b, c, d, x, y):
    return abs(min(max(x, a), c) - x) + abs(min(max(y, b), d) - y)


def solve(n):
    maze = [[True for j in range(101)] for i in range(101)]
    a, b, c, d = map(int, input().split())
    for row in maze[a:c+1]:
        for i in range(b, d+1):
            row[i] = False

    xs = []
    ys = []
    damage = 0
    for i in range(n+1):
        x, y = map(int, input().split())
        xs.append(x)
        ys.append(y)

    for i in range(n):
        now_x = xs[i]
        now_y = ys[i]
        nx = xs[i+1]
        ny = ys[i+1]
        p1 = f(a, b, c, d, now_x, now_y) + f(a, b, c, d, nx, ny)
        p2 = abs(now_x - nx) + abs(now_y - ny)
        if p1 <= p2:
            damage += p1
            if maze[now_x][now_y]:
                damage -= 1
        else:
            damage += p2
        # damage += min(f(a, b, c, d, now_x, now_y) + f(a, b, c, d, nx, ny), abs(now_x - nx) + abs(now_y - ny))

    print(damage)



def main():
    while True:
        n = int(input())
        if n == 0:
            break
        solve(n)


main()
