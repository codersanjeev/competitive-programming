t = int(input())
for _ in range(t) :
    e = int(input())
    edges = []
    for i in range(e) :
        x, y = map(int, input().split())
        edges.append(x)
        edges.append(y)
    set_edges = set(edges)
    print(len(set_edges))
        