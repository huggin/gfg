# User function Template for python3


class Solution:
    def nthPoint(self, n):
        # Code here
        MOD = int(1e9 + 7)
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n + 1):
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD

        return dp[n]


# {
# Driver Code Starts
# Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.nthPoint(n)
        print(ans)
# } Driver Code Ends
