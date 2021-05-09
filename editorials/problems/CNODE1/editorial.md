Tags: Heaps

The node with the minimum cumulative distance would be the one right in the centre.
That node would essentially be the median node based on its distance value.

The problem's now reduced to keeping track of the median of a list that's being updated.

Given a list, sorted in ascending order, if we were to know the largest element of the left half of the list, and the smallest element of the right half, we could determine the median of that list.

Implementation

To achieve what's required, we could maintian two heaps, a max heap for the left half, and a min heap for the right.
Each number could be added into one of the two heaps, and the sizes of the heaps could be balanced to make sure they're storing two halves of the current sequence.

Initialize a max-heap left, and a min-heap right
1. If the number is greater than the top of left, it belongs to right, otherwise it belongs to left
2. In case the difference in size of the two heaps exceeds 2, the top of either right or left could be shifted to the other heap. (This way, it's guarranteed the size of the two heaps would be equal if there are an even number of elements in the current sequence, or the sizes would differ by exactly 1 in case the sequence size is odd.)
3. Since the heaps are always balanced relative to each other, the top of the larger heap will always correspond to the median of the sequence.