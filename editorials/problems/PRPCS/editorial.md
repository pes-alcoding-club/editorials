This is a simple dynamic programming subset sum problem.
Let the total sum be equal to S.

The state of dp would be as follows:
dp[i] = True if you can achieve the sum i from the given integers.

The transitions of your dp would be as follows:
dp[i + a[j]] = True iff dp[i] is True for the integer a[j]
Make sure i goes from S->0 and NOT 0->S to avoid double counting.

Once you have all the values you can achieve, just iterate through your dp array and see which value gives you the minimum subset sum ie:
ans = min(ans, max(i, S - i)) for i from 0 to S.
