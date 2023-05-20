# User function Template for python3


class Solution:
    def maximumProfit(self, prices, n, fee):
        # Code here
        a = 0
        b = -prices[0] - fee
        for i in range(1, n):
            a, b = max(prices[i] + b, a), max(b, a - prices[i] - fee)

        return a


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        prices = list(map(int, input().split()))
        fee = int(input())
        ob = Solution()
        print(ob.maximumProfit(prices, n, fee))
# } Driver Code Ends
