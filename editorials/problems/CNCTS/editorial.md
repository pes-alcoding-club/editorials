So for the first subtask, all we had to do is use DFS to check how many places can be visited by the given city after adding the roads.
So for each query of type 2, it would take O(N) time complexity.
For Q queries, the total time complexity would be O(NQ) which fits the given constraints.

For the second subtask, we need a faster solution. So for this, we would use a structure called DSU or disjoint set union.
For queries of type 1, we would `merge` (or in other words apply the `union`) the two cities. This takes O(logN) time complexity for each query.

As for query 2, we need another data structure within our DSU which stores the size (or in this case, the number of cities we can visit) for each set (or in this case, city).
If we do this, we can reduce the time taken to retrieve the size to just O(1).

So for Q queries our worst case time complexity would be just O(Q log N).
