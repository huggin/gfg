# User function Template for python3


class Solution:
    def minimumNumberOfDeletions(self, S):
        # code here
        n = len(S)
        dp = [[n for _ in range(n)] for _ in range(n)]
        for i in range(n):
            dp[i][i] = 0
        for i in range(n - 1):
            dp[i][i + 1] = 0 if S[i] == S[i + 1] else 1

        for k in range(2, n):
            for i in range(n - k):
                j = i + k
                if S[i] == S[j]:
                    dp[i][j] = dp[i + 1][j - 1]
                else:
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1

        return dp[0][n - 1]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        S = input()

        ob = Solution()
        print(ob.minimumNumberOfDeletions(S))
# } Driver Code Ends
