Title: Hack X<br>
Prerequisites: Arrays, xor<br>
Time Complexity: O(n)<br>
Method Used: Brute Force<br>
Instructions:<br>
We can follow the instructions and get the answer directly.
1. We will iterate through every element in the array and find the xor of each element and store it in a variable <strong>xr</strong>.
2. Along with that, we add the elements to get the sum of the array and store it into a variable <strong>sum</strong>.
3. We use an if statement to check if <b>2*xr</b> is equal to the sum as <strong>sum/xr=2</strong> and if it is we print <b>-1</b> which means the array already satisfies the condition else check if <b>xr</b>=0 if it is then print the <strong>sum</strong> as that would be the missing number, else print the two numbers which are missing <strong>a</strong> and <b>b</b>. Here <b>a</b> would be the <b>xr</b> and <strong>b</strong> would be <strong>xr+sum</strong> as:<br>
<b>A xor B=C</b> then <b>C+A+B</b> is always equal to <b>2*C</b>.<br>
Eg: 2 xor 6=4 and 4+6+2=16 which is 2*(6+2).
