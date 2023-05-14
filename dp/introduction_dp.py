# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3
import sys

sys.setrecursionlimit(1005)


class Solution:
    M = int(1e9 + 7)

    def solve(self, n):
        if n == 0:
            return 0
        if n == 1:
            return 1
        if self.dp[n] != -1:
            return self.dp[n]
        ans = (self.solve(n - 1) + self.solve(n - 2)) % self.M
        self.dp[n] = ans
        return ans

    def topDown(self, n):
        # Code here
        self.dp = [-1] * (n + 1)
        return self.solve(n)

    def bottomUp(self, n):
        # Code here
        if n == 0:
            return 0
        if n == 1:
            return 1
        a, b = 0, 1
        for i in range(2, n + 1):
            a, b = b, (a + b) % self.M

        return b


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        topDownans = ob.topDown(n)
        bottomUpans = ob.bottomUp(n)
        if topDownans != bottomUpans:
            print(-1)
        else:
            print(bottomUpans)
# } Driver Code Ends
