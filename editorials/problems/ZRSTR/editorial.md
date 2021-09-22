In this problem, there are only 3 cases you should consider:
1.  The string has only 0s. In this case the answer will be (n * k) _take care of overflows_
2.  The answer can be a substring of the original string S, but the answer is not a part of the suffix or the prefix
3.  If k > 1, check if the maximum substring lies in the combination fo suffix + prefix

