direction = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
]

# 8 p s
def bfs(start, goal): # goal is char
    visited = [[False] * w for i in range(h)]
    que = [(start, 0)]
    # visited[0][0] = True
    while que:
        (x, y), cnt = que.pop(0)

        if visited[y][x]:
            continue
        visited[y][x] = True
        if kb[y][x] == goal:
            return (x, y, cnt + 1)
        for d in direction:
            nx = x + d[0]
            ny = y + d[1]
            if 0 <= nx < w and 0 <= ny < h:
                que.append(((nx, ny), cnt + 1))
while True:
    h, w = map(int, input().split())
    if h == w == 0:
        break
    kb = [] 
    for i in range(h):
        kb.append(list(input()))
    S = list(input())
    ans = 0
    x, y = 0, 0
    for s in S:
        x, y, cnt = bfs((x, y), s)
        ans += cnt
    print(ans)
        