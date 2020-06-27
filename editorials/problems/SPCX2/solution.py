from sys import stdin

line = stdin.readline()
v = int(line.split()[0])
e = int(line.split()[1])

vertexToCluster = dict()
for vertex in range(0, v):
    vertexToCluster[vertex] = vertex

clusterToVertices = dict()
for vertex in range(0, v):
    clusterToVertices[vertex] = [vertex]

for i in range(0, e):
    line = stdin.readline()
    v1 = int(line.split()[0])
    v2 = int(line.split()[1])
    if (vertexToCluster[v1] != vertexToCluster[v2]):
        smaller = min(vertexToCluster[v1], vertexToCluster[v2])
        larger = max(vertexToCluster[v1], vertexToCluster[v2])
        for vertex in clusterToVertices[larger]:
            vertexToCluster[vertex] = smaller
            clusterToVertices[smaller].append(vertex)
        del clusterToVertices[larger]

permutations = v*v
for c in clusterToVertices:
    permutations -= len(clusterToVertices[c])*len(clusterToVertices[c])
    
print (int(permutations/2))