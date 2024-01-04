# User function Template for python3


class Solution:
    def TotalWays(self, N):
        # Code here
        dp = [0] * (N + 1)
        M = int(1e9 + 7)
        dp[0] = 1
        dp[1] = 2
        for i in range(2, N + 1):
            dp[i] = (dp[i - 1] + dp[i - 2]) % M

        return dp[N] * dp[N] % M


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        N = int(input())
        ob = Solution()
        ans = ob.TotalWays(N)
        print(ans)
# } Driver Code Ends
