# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def totalWays(self, n, m, grid):
        # Code here
        M = int(1e9 + 7)
        dp = [[0 for _ in range(m)] for _ in range(n)]
        dp[0][0] = 1 if grid[0][0] == 0 else 0
        for j in range(1, m):
            if grid[0][j] == 0:
                dp[0][j] = dp[0][j - 1]
            else:
                dp[0][j] = 0

        for i in range(1, n):
            if grid[i][0] == 0:
                dp[i][0] = dp[i - 1][0]
            else:
                dp[i][0] = 0

        for i in range(1, n):
            for j in range(1, m):
                if grid[i][j] == 0:
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M
                else:
                    dp[i][j] = 0

        return dp[n - 1][m - 1]


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = list(map(int, input().split()))
        grid = [list(map(int, input().split())) for _ in range(n)]
        ob = Solution()
        res = ob.totalWays(n, m, grid)
        print(res)
# } Driver Code Ends
