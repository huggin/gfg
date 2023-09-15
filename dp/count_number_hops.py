# User function Template for python3


class Solution:
    # Function to count the number of ways in which frog can reach the top.
    def countWays(self, n):
        # code here
        dp = [0] * (n + 1)
        dp[0] = 1
        M = int(1e9 + 7)
        for i in range(1, n + 1):
            dp[i] += dp[i - 1]
            if i >= 2:
                dp[i] += dp[i - 2]
            if i >= 3:
                dp[i] += dp[i - 3]
            dp[i] %= M

        return dp[n]


# {
# Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys

sys.setrecursionlimit(10**6)
# Contributed by : Nagendra Jha

if __name__ == "__main__":
    test_cases = int(input())
    for cases in range(test_cases):
        m = int(input())
        ob = Solution()
        print(ob.countWays(m))
# } Driver Code Ends
