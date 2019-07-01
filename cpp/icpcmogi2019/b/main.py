import sys


def solve(n):
    maze = [[True for j in range(101)] for i in range(101)]
    a, b, c, d = map(int, input().split())
    for row in maze[a:c+1]:
        for i in range(b, d+1):
            row[i] = False
    xs = []
    ys = []
    for i in range(n+1):
        x, y = map(int, input().split())
        xs.append(x)
        ys.append(y)
    ans = 0
    for i in range(1, n+1):
        dx = abs(xs[i-1] - xs[i])
        dy = abs(ys[i-1] - ys[i])
        mx = min(xs[i-1],  xs[i])
        my = min(ys[i-1],  ys[i])
        ans1 = 0
        for row in maze[mx:mx+dx+1]:
            ans1 += sum(row[my:my+dy+1])
        mx = -1
        my = -1
        mdx = 1000
        mdy = 1000
        ans2 = 0
        ans3 = 0
        if a <= xs[i-1] <= c and b <= ys[i-1] <= d:
            ans += ans1
        else:
            for xx,  yy in [(a, b), (a, d), (c, b), (c, d)]:
                dx = abs(xs[i-1] - xx)
                dy = abs(xs[i-1] - yy)
                if mdx + mdy > dx + dy:
                    mdx = dx
                    mdy = dy
                    mx = xx
                    my = yy
            mx = min(xs[i-1], mx)
            my = min(ys[i-1], my)
            ans21 = 0
            ans22 = 0
            for row in maze[mx:mx+mdx+1]:
                ans21 += sum(row[my:my+mdy+1])
            for ii in range(1, n+1):
                if mx <= ii <= mx+mdx:
                    ans22 += max(int(maze[ii][ys[i-1]]), 0)
            ans22 += sum(maze[mx+mdx][my:my+mdy+1])
            ans2 = min(ans21, ans22)
            mx = -1
            my = -1
            mdx = 1000
            mdy = 1000
            for xx,  yy in [(a, b), (a, d), (c, b), (c, d)]:
                dx = abs(xs[i] - xx)
                dy = abs(xs[i] - yy)
                if mdx + mdy > dx + dy:
                    mdx = dx
                    mdy = dy
                    mx = xx
                    my = yy
            mx = min(xs[i-1], mx)
            my = min(ys[i-1], my)
            ans31 = 0
            ans32 = 0
            for row in maze[mx:mx+mdx+1]:
                ans31 += sum(row[my:my+mdy+1])

            for ii in range(1, n+1):
                if mx <= ii <= mx+mdx:
                    ans32 += max(int(maze[ii][ys[i-1]]), 0)
            ans32 += sum(maze[mx+mdx][my:my+mdy+1])
            ans3 = min(ans31, ans32)
            ans += min(ans1, ans2+ans3)
    print(ans1, ans2, ans3)
    #print(a, b, c, d)
    #print(xs, ys)
    print(ans)


def main():
    while True:
        n = int(input())
        if n == 0:
            break
        solve(n)


main()
