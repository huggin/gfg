# User function Template for python3
from collections import defaultdict


class Solution:
    # Function to check whether there is a subarray present with 0-sum or not.
    def subArrayExists(self, arr, n):
        ##Your code here
        # Return true or false

        d = defaultdict(int)
        d[0] = 1
        curr = 0
        for i in range(n):
            curr += arr[i]
            if curr in d:
                return 1
            d[curr] = 1

        return 0


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())
    while T > 0:
        n = int(input())
        arr = [int(x) for x in input().strip().split()]
        if Solution().subArrayExists(arr, n):
            print("Yes")
        else:
            print("No")

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends
