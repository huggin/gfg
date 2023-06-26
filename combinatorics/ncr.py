# User function Template for python3


class Solution:
    def nCr(self, n, r):
        # code here
        if r > n:
            return 0

        M = int(1e9 + 7)
        dp = [[1 for _ in range(n + 1)] for _ in range(2)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            dp[i % 2][0] = 1
            dp[i % 2][i] = 1
            for j in range(1, i):
                dp[i % 2][j] = (dp[1 - i % 2][j] + dp[1 - i % 2][j - 1]) % M

        return dp[n % 2][r]


# {
# Driver Code Starts
# Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, r = [int(x) for x in input().split()]

        ob = Solution()
        print(ob.nCr(n, r))
# } Driver Code Ends
