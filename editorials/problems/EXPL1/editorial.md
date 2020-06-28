Title: Exploring Planets<br>
Difficulty: Hard<br>
Prerequisites: Backtracking, BFS<br>
Time Complexity:O(n!)<br>
Method Used: Backtracking, DFS<br>
Instructions:<br>
We use a backtracking algorithm to find the maximum number of planets visited.
1. Initially, the max number of planets visited is set to zero. The first step is to find a planet such that, the time taken to travel from Earth to that planet is less than or equal to <b>X</b>. Once this planet is found, the element in the <b>visited array</b> corresponding to this planet is set to 1.
2. We call the function which will help us find the most planets visited.
3. There exists a variable that keeps track of the time taken by the current best path. (The best path is the one that covers the most planets while taking the least time to cover these planets). There exists a temporary array to keep track of the current path <b>temp</b> and another array to keep track of the best path <b>ans</b>.
4. In the backtracking function, the following procedure takes place:It iterates through a row of the 2-dimensional matrix. This row is the current planet that the rocket is on. If a particular planet is not visited and the time taken to reach it from the current planet is within the limit, then that particular planet is marked as visited, and this planet is added to the temporary array. If from a particular path, there exists no way to proceed further, then the current path status is compared with the best path status, and it is updated if necessary. The same goes on until a way to proceed is found. This is known as backtracking.
