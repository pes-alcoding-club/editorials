Title: CNST1

Difficulty: Easy.

Prerequisites: Implementation, Graph Theory, BFS.

Explanation: 
1. We need to check if a star belongs to a separate constellation or not. One way of doing that is when we encounter a star in the grid,
   we should check if it has a star to adjacent left and just above it. A new constellation is marked when a gap is present on both sides i.e. no star. 
   We need not check if it has a star on adjacent right or just below it(which are checked later).
2. grid[0][0] is a special(first) case. If a star is present, raise constellation count.
3. For edge cases, Row 1, we only check for adjacent left cell and if a star is not present, we mark it as a new constellation. Similarly for Column 1, we only check for cell just above it.

Time Complexity: O(m*n)
