**Tags**: Math, Bitwise Operation

We can rearrange the equation using the *distributive* property:

(A **&** B) **|** (A **&** C)= A **&** (B **|** C).

 
Hence we can simplify the equation down to (**OR** of elements of **A** ) **AND** (**OR** of elements of **B**)

  
Eg:

1 2 3

4 5

  

Sol:

-> (1 **&** 4) **|** (1 **&** 5) **|** (2 **&** 4) **|** (2 **&** 5) **|** (3 **&** 4) **|** (3 **&** 5) (Using *distributive* property)

-> (1 **&** (4 **|** 5)) **|** (2 **&** (4 **|** 5) **|** (3 **&** (4 **|** 5)) (Using *distributive* property)

-> (4 **|** 5) **&** (1 **|** 2 **|** 3)

This gives us the answer **1**.

  

Time Complexity:

O(m+n) to find bitwise **OR** of every element of A and B