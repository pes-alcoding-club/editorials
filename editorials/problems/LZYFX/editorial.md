Tags: Hashmap, Sets

Since the characters are independent of upper or lower case, we can make every character lower case (or upper case).

The problem then requires you to check the occurence of all 26 characters, a set can be used to store all unique character.
If the size of the set's 26, it implies that all characters occur in the string.

Alternatively, a hashmap of sorts can be used to track the occurence of each character. The hashmap can then be traversed to 
verify 26 occurences.
