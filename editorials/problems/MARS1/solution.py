typeOfStation = []
graph = []
depth = []
visited = []
parent = []
distanceFromParent = []

def findPath(a, b):

    global depth, parent, visited, distanceFromParent

    pathA = [a]
    pathB = [b]

    while (a != b):
        if depth[a] > depth[b]:
            pathA.append(parent[a])
            a = parent[a]

        elif depth[b] > depth[a]:
            pathB.append(parent[b])
            b = parent[b]

        else:
            pathA.append(parent[a])
            pathB.append(parent[b])
            a = parent[a]
            b = parent[b]

    pathB = pathB[::-1]

    return (pathA + pathB[1:], a)
    

def bfs(root):

    global depth, parent, visited, distanceFromParent

    depth[root] = 0
    parent[root] = -1
    visited[root] = 1
    distanceFromParent[root] = 0

    queue = [root]

    while queue:
        s = queue.pop()

        for node in graph[s]:
            neighbour = node[0]
            if visited[neighbour] == 0:
                visited[neighbour] = 1
                queue.append(neighbour)
                depth[neighbour] = depth[s] + 1
                parent[neighbour] = s
                distanceFromParent[neighbour] = node[1]
    

def calculate(path, lca):

    global depth, parent, visited, distanceFromParent

    cost = 0
    distance = 0

    a = path[0]
    b = path[-1]

    if a == b:
        return 0

    check = (a != lca)

    while check:

        if (typeOfStation[a] and distance > 0):
            cost += 2 ** (distance)
            distance = 0
        
        if a == lca:
            check  = 0
        else:
            distance += distanceFromParent[a]
            a = parent[a]

    check = (a != lca)

    while b != lca:

        if (typeOfStation[b] and distance > 0):
            cost += 2 ** (distance)
            distance = 0

        if b == lca:
            check = 0
        else:
            distance += distanceFromParent[b]
            b = parent[b]

    if distance:
        cost += 2 ** distance

    return cost

for _ in range(int(input())):

    graph = []
    depth = []
    visited = []
    parent = []
    typeOfStation = []
    distanceFromParent = []

    n, q, c = list(map(int, input().split(' ')))
    typeOfStation = list(map(int, input().split(' ')))

    graph = [[] for i in range(n)]

    for i in range(n-1):
        u, v, d = list(map(int, input().split(' ')))
        graph[u-1].append([v-1, d])
        graph[v-1].append([u-1, d])

    depth = [-1 for i in range(n)]
    visited = [0 for i in range(n)]
    parent = [-1 for i in range(n)]
    distanceFromParent = [0 for i in range(n)]

    bfs(c - 1)

    for i in range(q):
        a, b = list(map(int, input().split(' ')))
        path, lca = findPath(a-1, b-1)
        ans = calculate(path, lca)
        print(ans)