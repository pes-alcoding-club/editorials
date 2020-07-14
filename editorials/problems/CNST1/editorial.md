Title: CNST1

Difficulty: Easy.

Prerequisites: Implementation, Graph Theory, BFS.

Explanation: 
1. The problem is basically finding the number of connected components, where 2 cells (x, y) and (xx, yy) are said to be connected 
only if `x + 1 = xx` or `x - 1 = xx` or `y + 1 = yy` or `y - 1 = yy`
2. This can be achieved by a simple BFS on the grid.
3. Traverse through the array, on every occurence of a '1', perform a BFS with that cell as the root, and delete that particular component from the grid. This can be done either by using a visited array, or just marking the visited cells as 0 in the grid. 
4. The number of BFSs carried out will provide the value of the number of constallations/components.

Time Complexity: O(m*n)
