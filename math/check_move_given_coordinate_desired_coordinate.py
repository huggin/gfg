# User function Template for python3
import math


class Solution:
    def isPossible(self, x, y, a, b):
        # code here
        x, y, a, b = abs(x), abs(y), abs(a), abs(b)
        return 1 if math.gcd(x, y) == math.gcd(a, b) else 0


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        x, y, a, b = map(int, input().split())

        ob = Solution()
        print(ob.isPossible(x, y, a, b))
# } Driver Code Ends
