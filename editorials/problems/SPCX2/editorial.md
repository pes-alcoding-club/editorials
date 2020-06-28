Title: SPCX2

Difficulty: Medium.

Prerequisites: Graph Theory, Depth First Search(DFS) or Disjoint Sets.

Explanation: 
1. This problem can be modelled as a Graph Problem. The very first step is to compute how many different countries are there. 
2. We can either apply Depth First Search (DFS), or the concept of Disjoint Sets, to calculate how many different connected components are present in the graph, 
where the vertices are represented by the astronauts, and the astronauts from the same country form one connected component. 
3. After we get how many connected components are present, we just need to calculate the number of ways of selecting two astronauts from two different connected components. 
4. So, for the number of ways of selecting two astronauts from different components, we subtract the number of ways of selecting two astronauts from the same component from the total numbers of ways of selecting two astronauts.

Time Complexity: O(n*p)
