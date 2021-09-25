From the question, we see that we need to remove elements in increasing order.
We also need to keep a count of the number of indices removed which are less than the next smallest element we need to remove.
To do this, we can use a segment tree or a fenwick tree where we keep track of the number of elements we have removed from index 0 to index i.
We start by sorting the values of the patience with their index annotated. Then for each index of the new array, we process the number of indices that were removed before the current index. We then mark the current index as having been used.

The given solution can also be solved using Fenwick trees or Ordered Sets.
The editorial contains the Segment Tree approach.
