# User function Template for python3


class Solution:
    def countWays(self, n, k):
        # code here.
        if n == 1:
            return k

        MOD = int(1e9 + 7)
        dp = [0 for _ in range(n + 1)]
        dp[0] = 1
        dp[1] = k
        dp[2] = k * k
        for i in range(3, n + 1):
            dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]) % MOD

        return dp[n]


# {
# Driver Code Starts

# Initial Template for Python 3


t = int(input())
for _ in range(0, t):
    x = list(map(int, input().split()))
    n = x[0]
    k = x[1]
    ob = Solution()
    ans = ob.countWays(n, k)
    print(ans)

# } Driver Code Ends
