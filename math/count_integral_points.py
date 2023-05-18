# User function Template for python3
import math


class Solution:
    def countIntegralPoints(self, x1, y1, x2, y2):
        # code here
        if x1 == x2:
            return max(0, abs(y1 - y2) - 1)
        if y1 == y2:
            return max(0, abs(x2 - x2) - 1)
        return math.gcd(abs(x1 - x2), abs(y1 - y2)) - 1


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        x1, y1, x2, y2 = map(int, input().split())

        ob = Solution()
        print(ob.countIntegralPoints(x1, y1, x2, y2))
# } Driver Code Ends
