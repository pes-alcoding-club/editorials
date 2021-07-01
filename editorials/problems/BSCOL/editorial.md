Title: BSCOL

Difficulty: Medium

Prerequisites: DP, Math.

Explanation:

1. Note, that this is a basic DP problem where the states depend on which school the student is at (4) and the number of time units left (T). The recurrence can be built by noticing that at each school you have 3 options to go to.
2. This solution does not pass for large testcases due to the size of the inputs. Here we can notice that schools A, B and C are essentially the same.
   We can reorient the problem to one with 2 states, D or ABC and you can stay at the ABC state for multiple minutes.
   So we can reject a DP solution and solve the problem using pure math and combinatorics.
   At T = 0 (in 0 minutes), the number of ways to get to D and back is 1, while the number of ways to get from A, B or C to D is 0.

At an instance of X units of time,

The number of ways to get to D at X minutes is => 3 \* (number of ways to get to A, B, C at X - 1 minutes)

The number of ways to get to A, B or C at X minutes is => (number of ways to get to D at X - 1 minutes) + 2 \* (number of ways to get to A, B or C at X - 1 minutes), since you are already at either A, B or C.

Also make sure to use modular arithmetic.

Time Complexity: O(N)

Space Complexity: O(1)
