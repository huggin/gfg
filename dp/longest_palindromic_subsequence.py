# User function Template for python3
import sys

sys.setrecursionlimit(2000)


class Solution:
    def longestPalinSubseq(self, S):
        # code here
        n = len(S)
        dp = [[-1 for _ in range(n)] for _ in range(n)]

        def f(i, j):
            if i > j:
                return 0
            if i == j:
                return 1
            if dp[i][j] != -1:
                return dp[i][j]

            if S[i] == S[j]:
                dp[i][j] = 2 + f(i + 1, j - 1)
            else:
                dp[i][j] = max(f(i + 1, j), f(i, j - 1))
            return dp[i][j]

        return f(0, n - 1)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        ob = Solution()
        ans = ob.longestPalinSubseq(s)
        print(ans)
# } Driver Code Ends
