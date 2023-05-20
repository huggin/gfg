# User function Template for python3


class Solution:
    def maximumProfit(self, prices, n):
        # Code here
        if n < 2:
            return 0
        dp = [[0 for _ in range(n)] for _ in range(2)]
        dp[1][0] = -prices[0]
        dp[0][1] = 0 if prices[1] < prices[0] else prices[1] - prices[0]
        dp[1][1] = max(dp[1][0], -prices[1])
        for i in range(2, n):
            dp[0][i] = max(dp[1][i - 1] + prices[i], dp[0][i - 1])
            dp[1][i] = max(dp[0][i - 2] - prices[i], dp[1][i - 1])

        return dp[0][n - 1]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        prices = list(map(int, input().split()))
        ob = Solution()
        print(ob.maximumProfit(prices, n))
# } Driver Code Ends
