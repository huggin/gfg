# User function Template for python3
class Solution:
    def bitonic(self, arr, n):
        # code here
        dp = [1] * n
        for i in range(1, n):
            if arr[i] >= arr[i - 1]:
                dp[i] = dp[i - 1] + 1

        dp2 = [1] * n
        for i in range(n - 2, -1, -1):
            if arr[i] >= arr[i + 1]:
                dp2[i] = dp2[i + 1] + 1

        ans = 0
        for i in range(n):
            ans = max(ans, dp[i] + dp2[i] - 1)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.bitonic(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends
