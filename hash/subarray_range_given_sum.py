# User function Template for python3
from collections import defaultdict


class Solution:

    # Complete this fuction
    # Function to count the number of subarrays which adds to the given sum.
    def subArraySum(self, arr, n, s):
        # Your code here
        d = defaultdict(int)
        d[0] = 1
        ans = 0
        curr = 0
        for a in arr:
            curr += a
            ans += d[curr - s]
            d[curr] += 1
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())
    while T > 0:

        n = int(input())
        arr = [int(x) for x in input().strip().split()]
        sum = int(input())

        print(Solution().subArraySum(arr, n, sum))

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends
