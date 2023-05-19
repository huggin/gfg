# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def checkSubsequenceSum(self, N, arr, K):
        # Code here
        dp = [0] * (K + 1)
        dp[0] = 1
        for a in arr:
            for i in range(K, -1, -1):
                if i - a >= 0:
                    dp[i] += dp[i - a]

        return dp[K] >= 1


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        K = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        possible = ob.checkSubsequenceSum(N, arr, K)
        print("Yes" if possible else "No")
# } Driver Code Ends
