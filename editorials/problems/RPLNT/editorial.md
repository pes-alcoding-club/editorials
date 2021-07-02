Ross can uniquely identify the dinosaurs iff the number of bones in each sculpture is a unique number.
There are many ways to implement the solution, here is one way.

Maintain a hashed map or a dictionary (depending on the language you are coding in) containing the number of occurances of each number. If any number occurs more than once, then Ross cannot identify the dinosaurs.

Depending on your solution, the time complexity can be from O(n) to O(n log n).
