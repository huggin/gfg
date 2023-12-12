# User function Template for Python3


class Solution:
    def maxGold(self, n, m, M):
        # code here
        dp = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(n):
            dp[i][0] = M[i][0]

        for j in range(1, m):
            for i in range(n):
                dp[i][j] = dp[i][j - 1]
                if i - 1 >= 0:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1])
                if i + 1 < n:
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1])
                dp[i][j] += M[i][j]

        ans = 0
        for i in range(n):
            ans = max(ans, dp[i][m - 1])

        return ans


# {
# Driver Code Starts
# Initial Template for Python3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = [int(x) for x in input().split()]
        tarr = [int(x) for x in input().split()]
        M = []
        j = 0
        for i in range(n):
            M.append(tarr[j : j + m])
            j = j + m

        ob = Solution()
        print(ob.maxGold(n, m, M))
# } Driver Code Ends
