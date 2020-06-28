# Basic Idea

Compare the strings from the **right to left** as backspaces remove characters
in this manner, and to **keep track** of encountered backspace characters.

# Explanation	

So we start from right end of the strings. If we encounter a **'#'** 
character, we keep track of it by incrementing a counter for each string.
If the previous character is a letter, we simply reduce the counter to show that 
a backspace has been used. Now, if at any point a counter becomes zero, it means that the 
previous character will be a letter and will be present in the final string, unless it is a **'#'**. 
So we need to check its equality with the character in other string.
If they are not equal, we know straightaway that the final strings cannot be equal and we stop further comparisons.
Also, if any of the strings get traversed before the other, they cannot be equal.
Otherwise, the two strings will give same output.