# User function Template for python3


class Solution:
    # Function to find the smallest positive number missing from the array.
    def missingNumber(self, arr, n):
        # Your code here
        s = set(arr)
        for i in range(1, 1000001):
            if i not in s:
                return i

        return -1


# {
# Driver Code Starts
# Initial Template for Python 3


import math


def main():
    T = int(input())
    while T > 0:
        n = int(input())

        arr = [int(x) for x in input().strip().split()]

        ob = Solution()
        print(ob.missingNumber(arr, n))

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends
