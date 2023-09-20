# User function Template for python3


class Solution:
    # Function to find the maximum money the thief can get.
    def FindMaxSum(self, a, n):
        # code here
        if n == 1:
            return a[0]
        dp = [0] * n
        dp[0] = a[0]
        for i in range(1, n):
            dp[i] = a[i]
            if i - 3 >= 0:
                dp[i] += max(dp[i - 3], dp[i - 2])
            elif i - 2 >= 0:
                dp[i] += dp[i - 2]

        return max(dp[n - 1], dp[n - 2])


# {
# Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys

sys.setrecursionlimit(10**6)
# Contributed by : Nagendra Jha

if __name__ == "__main__":
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        a = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.FindMaxSum(a, n))
# } Driver Code Ends
