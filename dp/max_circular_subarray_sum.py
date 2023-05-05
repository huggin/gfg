# User function Template for python3

# Complete this function
# Function to find maximum circular subarray sum.
import sys
import math


def circularSubarraySum(arr, n):
    # Your code here
    s = 0
    all_neg = 1
    for a in arr:
        s += a
        if a > 0:
            all_neg = 0

    if all_neg:
        return max(arr)
    ans = -1000001
    curr = 0
    for a in arr:
        if curr + a >= 0:
            curr += a
        else:
            curr = 0
        ans = max(ans, curr)

    total = 0
    curr = 0
    for a in arr:
        if curr + a <= 0:
            curr += a
        else:
            curr = 0
        total = min(total, curr)

    ans = max(ans, s - total)
    return ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    T = int(input())
    while T > 0:
        n = int(input())

        arr = [int(x) for x in input().strip().split()]

        print(circularSubarraySum(arr, n))

        T -= 1

# } Driver Code Ends
