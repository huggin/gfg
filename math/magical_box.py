# User function Template for python3
import math


class Solution:
    def maxVolume(self, p, s):
        x = (p - math.sqrt(p * p - 4 * 6 * s)) / 12
        y = p / 4 - 2 * x
        return x * y * x


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        p, s = [int(x) for x in input().split()]

        ob = Solution()
        print("%.5f" % ob.maxVolume(p, s))
# } Driver Code Ends
