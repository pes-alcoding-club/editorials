Tags: Binary Search

To find the minimum number of students that need to be moved around, we need to find the maximum number
of students that can stay in place. To do this, we must find the longest increasing subsequence (LIS).

It should be noted that this could've been a dynamic programming problem if the constraints allowed it.

Eg.
2 4 1 5 3 6 7

The longest increasing sequence in this example is 2 4 5 6 7.
Numbers that are left out are 1 and 3, these are the numbers that are needed to be rearranged.
Now, all we have to do is find len(sequence) - len(LIST) to get our answer.

Our goal is to find the longest increasing sequence.
We'll start by initializing an array *LIS* to *height[0]* (First element of height). The length of this array will provide us the length of the longest sequence. 

1. Iterating through each element of the array height we check if element *height[i]* is greater than the last element of LIS. If it is, then the element is added to the end of LIS. 
(This step ensures that LIS is a sorted list and, an element that is larger than the last element of LIS will be part of the longest sequence)

2. If the element is not larger then we'll have to find its position in LIS. 
This is done by finding the lower bound(The next smallest number just greater than or equal to the element) in LIS.
This can be solved using binary search, or the in-build lower_bound() (C++) or bisect_left() (python)
Let this lower bound index be **idx**
LIS[idx] is updated to height[i].

At the end, the size of LIS corresponds to the length of the longest increasing subsequence, but it must be noted that the elements
itself do not correspond to a valid longest increasing subsequence.