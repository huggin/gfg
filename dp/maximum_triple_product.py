# User function Template for python3


class Solution:
    def maxProductSum(self, n, arr):
        # code here
        a = [1]
        a.extend(arr)
        a.append(1)
        dp = [[0 for _ in range(n + 2)] for _ in range(n + 2)]
        for i in range(1, n + 1):
            dp[i][i] = a[i - 1] * a[i] * a[i + 1]

        for k in range(1, n):
            for i in range(1, n - k + 1):
                for j in range(i, i + k + 1):
                    dp[i][i + k] = max(
                        dp[i][i + k],
                        dp[i][j - 1]
                        + dp[j + 1][i + k]
                        + a[j] * a[i - 1] * a[i + k + 1],
                    )

        return dp[1][n]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxProductSum(n, arr)
        print(ans)
        tc -= 1
# } Driver Code Ends
