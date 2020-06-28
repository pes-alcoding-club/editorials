# Basic Idea 

Given the constraints, it is clear that this mapping can be represented as a tree and the problem then becomes the LCA problem.

# Explanation

Maintain a graph in the form of an adjacency list. Once you have stored the graph.
Do a single bfs on the graph, in each step store the depth, parent, and distance from parent of each station and mark this station as visited.
After this, calculate the LCA for A and B in each query by traversing backwards 
towards the parents of A and B till both the nodes are the same.
After this, starting from A increase the values of distance by the distance between the node 
and the next node in the path and everytime a normal station is encountered, reset distance to zero 
and add the 2 ^ (current distance) to the original cost.
Repeat this till we reach station B.