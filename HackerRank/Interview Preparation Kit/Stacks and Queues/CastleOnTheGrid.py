from collections import deque

n, inf = int(input()), float('inf')
grid = [list(input()) for _ in range(n)]
x_beg, y_beg, x_end, y_end = map(int, input().split())
dist = [n * [inf] for _ in range(n)]
dist[x_beg][y_beg], grid[x_end][y_end] = 0, '*'

queue = deque([(x_beg, y_beg)])
while queue:
    x0, y0 = queue.popleft()
    d = dist[x0][y0]
    if grid[x0][y0] == '*':
        break
    for nbr in [range(x0+1, n), range(x0-1, -1, -1)]:
        for x in nbr:
            if grid[x][y0] == 'X':
                break
            if dist[x][y0] == inf:
                dist[x][y0] = d + 1
                queue.append((x, y0))
    for nbr in [range(y0+1, n), range(y0-1, -1, -1)]:
        for y in nbr:
            if grid[x0][y] == 'X':
                break
            if dist[x0][y] == inf:
                dist[x0][y] = d + 1
                queue.append((x0, y))
print(d)