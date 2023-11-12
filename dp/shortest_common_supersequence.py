# User function Template for python3


class Solution:
    # Function to find length of shortest common supersequence of two strings.
    def shortestCommonSupersequence(self, X, Y, m, n):
        # code here
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(m + 1):
            dp[i][0] = i
        for i in range(n + 1):
            dp[0][i] = i
        for i in range(m):
            for j in range(n):
                if X[i] == Y[j]:
                    dp[i + 1][j + 1] = dp[i][j] + 1
                else:
                    dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j]) + 1

        return dp[m][n]


# {
# Driver Code Starts
# Initial Template for Python 3

# contributed by RavinderSinghPB
if __name__ == "__main__":
    t = int(input())
    for tcs in range(t):
        X, Y = input().split()

        print(Solution().shortestCommonSupersequence(X, Y, len(X), len(Y)))

# } Driver Code Ends
