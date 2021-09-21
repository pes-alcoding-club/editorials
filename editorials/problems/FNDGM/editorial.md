Tags:sorting

For the given queries we know that the gem is hidden in one of the coordinates. **Our job is to find the point which doesn't belong to any of the intervals**.

1. We store the (L_i,R_i) values and sort it.

2. We keep track of a variable *prev* and traverse through the array. We'll check if the *prev* element is in the given range L_i and R_i:
    1. If it is then the prev value is changed to R_i+1.
    2. If not then the value is kept the same.

3. At the end we'll end up with the *prev* value which is not part of any interval. This gives us our answer.