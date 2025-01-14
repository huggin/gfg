# {
# Driver Code Starts
# Initial Template for Python 3
import sys


# } Driver Code Ends
# User function Template for python3
class Solution:
    def minCost(self, height):
        # code here
        n = len(height)
        if n == 1:
            return 0
        dp = [0] * n
        dp[1] = abs(height[1] - height[0])
        for i in range(2, n):
            dp[i] = min(
                dp[i - 2] + abs(height[i] - height[i - 2]),
                dp[i - 1] + abs(height[i] - height[i - 1]),
            )

        return dp[n - 1]


# {
# Driver Code Starts.

if __name__ == "__main__":
    input_lines = sys.stdin.read().splitlines()

    pointer = 0

    t = int(input_lines[pointer].strip())
    pointer += 1

    for _ in range(t):
        arr = list(map(int, input_lines[pointer].strip().split()))
        pointer += 1

        ob = Solution()
        print(ob.minCost(arr))
        print("~")

# } Driver Code Ends
