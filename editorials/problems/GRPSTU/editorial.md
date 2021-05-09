We can look at the problem as a graph problem, where each student is a node and each friendship is an edge.

Here the problem requires a bipartite graph check  where each group ruby and emerald can be considered as colors to be assigned to nodes. We need to check if the given graph is bipartite.

One way to do this is to run a dfs from a node and assign a color to it. Then all its children must be assigned an opposite color.
While runnning the dfs, if we have already visited a child, we must check if it has the same color as its parent. 
If it does, then it is impossible to color the graph in a bipartite fashion.

The next observation to be made is that, if a graph is bipartite there are 2 ways to color the graph.
One is with the starting node as ruby and all its children as emerald and vice versa.

The final observation is that, since the graph may have many connected components, the number of ways to color the graph will be 2 ^ (number of connected components) since all colorings of connected components are independent.

So we need to check for the number of connected components and return 2 ^ (number of connected components).

Thus the answer is,
0 if the graph is not bipartite.
else it is 2 ^ (number of connected components).