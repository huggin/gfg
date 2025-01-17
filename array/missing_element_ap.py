# User function Template for python3


class Solution:
    def findMissing(self, arr):
        # code here
        n = len(arr)
        d = (arr[-1] - arr[0]) // n
        s = set(arr)
        for a in range(arr[0], arr[-1], d):
            if a not in s:
                return a
        return -1


# {
# Driver Code Starts
# Initial Template for Python 3
import sys
import math


def main():
    input = sys.stdin.read
    data = input().strip().split("\n")

    t = int(data[0])
    solution = Solution()

    for i in range(1, t + 1):
        arr = list(map(int, data[i].split()))
        print(solution.findMissing(arr))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
