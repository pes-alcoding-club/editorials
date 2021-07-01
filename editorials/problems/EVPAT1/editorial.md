Tags: Bitmasks, Hashmaps

The problem requires us to find the longest substring with an even occurence of some particular numbers. From the statement, it's 
fairly obvious that if we were to store something, we'd have to store the parity of each number's occurence. This, of course can easily be done. But this information alone isn't enough, we'd also need to know the parity of the numbers' occurence at each index, and somehow find 
the pair of indices that's farthest apart such that the parities are even. This certainly would be an expensive approach, how do we do better.

Now, it can be noticed that if a particular number D occurs at position x, it occurs an odd number of times in the interval [0, x], and an odd number of times again at a position x + n, then the subarray (x, x + n] contains an even occurence of D. The same if the occurence at x and x + n were even. So, we need a mechanism to compare the parities of the occurence of numbers in B between two indices, if they're the same, then the subarray between those two indices must be considered.

To remember the parity of the occurence of a particular number until a given index, only 1 bit is required. 0 corresponding to "even", and 1 corresponding to "odd". The constraints mention that the number of unique elements in B are less than 20. Hence, an integer can easily be
used to encode this data, where each bit would correspond to the parity of a given number. This integer effectively stores the parity of the occurences of numbers in B till a particular index. Let's call this integer a "parity mask". If the parity masks at two indices of the array are the same, it implies that the the subarray between the two indices can be considered for its length.

All we need to do now is compute the "parity mask" for a given index. For this, we need to map a given number in B to a bit position in the "parity mask", and keep updating that bit. Now to map a "parity mask" to a given index, a hashmap can be used. We need to only remember index of the first occurence of a particular "parity mask". Each time we encounter a parity mask, we lookup the hashmap for the first occurence, find the difference between the current index and the first occurence, consider it for our solution.

Implementation
1. `bitMap` is the hashmap that maps a number in B to its bit index in the "parity mask"
2. `occur` is the hashmap that stores the first occurence of a given "parity mask"
3. `cur` is the integer used as our "parity mask"
4. Now, for every element of the array. We check if the number belongs to `B`. We can use `bitMap` to check for that condition.
If it does, we toggle the parity of the corresponding bit in `cur`.
5. If `cur` does not exist in `occur`, it implies that this is the first occurence of `cur` and we add it to `occur`.
6. Now we check the last occurence of `cur` in `occur`. The difference between the current index and the last occurence
is the length of the longest valid subarray that ends at our current position.