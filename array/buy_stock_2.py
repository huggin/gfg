# User function Template for python3


class Solution:
    def maximumProfit(self, prices, n):
        # Code here
        ans = 0
        prev = 0
        for i in range(1, n):
            if prices[i] > prices[prev]:
                ans += prices[i] - prices[prev]
            prev = i

        return ans


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
