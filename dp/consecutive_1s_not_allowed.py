# User function Template for python3
class Solution:
    def countStrings(self, n):
        # code here

        dp = [[0 for _ in range(n + 1)] for _ in range(2)]
        dp[0][0] = 1
        dp[1][0] = 1
        MOD = int(1e9 + 7)
        for i in range(n):
            dp[0][i + 1] = (dp[0][i] + dp[1][i]) % MOD
            dp[1][i + 1] = dp[0][i]

        return (dp[0][n - 1] + dp[1][n - 1]) % MOD


# {
# Driver Code Starts
# Initial Template for Python 3


# Driver code
if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        ob = Solution()
        ans = ob.countStrings(n)
        print(ans)
        tc = tc - 1
# } Driver Code Ends
