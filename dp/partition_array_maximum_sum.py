# User function Template for python3


class Solution:
    def go(self, a, n, i, k, dp):
        if i == n:
            return 0
        if dp[i] != -1:
            return dp[i]

        ma = a[i]
        ans = ma + self.go(a, n, i + 1, k, dp)
        for j in range(i + 1, min(n, i + k)):
            ma = max(ma, a[j])
            ans = max(ans, ma * (j - i + 1) + self.go(a, n, j + 1, k, dp))

        dp[i] = ans
        return ans

    def solve(self, n, k, arr):
        # Code here
        dp = [-1] * n
        return self.go(arr, n, 0, k, dp)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = input().split()
        n = int(n)
        k = int(k)
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.solve(n, k, arr))
# } Driver Code Ends
