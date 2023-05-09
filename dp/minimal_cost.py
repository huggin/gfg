# User function Template for python3


class Solution:
    def minimizeCost(self, height, n, k):
        dp = [1e9] * n
        dp[0] = 0
        for i in range(1, n):
            for j in range(1, k + 1):
                if i - j >= 0:
                    dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j]))

        return dp[n - 1]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        height = list(map(int, input().split()))
        ob = Solution()
        print(ob.minimizeCost(height, n, k))
# } Driver Code Ends
