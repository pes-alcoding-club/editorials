Tags: Dynamic Programming

A valid subset contains points that have the following property: if we sort them increasingly by the x-coordinate, they will be sorted decreasingly by the y-coordinate.

First we sort all points, this way it's guarranteed that the x coordinates are in ascending order, now for a given set of coordinates, we find the number of coordinates before it which have the y coordinate greater than equal to it.

Hence, to count the total number of subsets, we can come up with the following dynamic programming solution:

DP[i] = the number of valid subsets such that the point with the greatest x-coordinate is "i".
We build DP[i] by iterating j along 0 to i - 1, such that DP[i] += DP[j] where j.x < i.x and j.y > i.y