# User function Template for python3
from collections import Counter


def LargButMinFreq(arr, n):
    # code here
    c = Counter(arr)

    ans = -1
    f = 1000000
    for k in c:
        if c[k] < f or c[k] == f and k > ans:
            f = c[k]
            ans = k

    return ans


# {
# Driver Code Starts
# Initial Template for Python 3

t = int(input())
# Iterating over test cases
for _ in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(LargButMinFreq(arr, n))
# } Driver Code Ends
