# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def longestIncreasingSubsequence(self, N, arr):
        # Code here
        dp = [1] * N
        p = [-1] * N
        max, pos = 0, -1
        for i in range(N):
            for j in range(i):
                if arr[i] > arr[j] and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    p[i] = j

            if max < dp[i]:
                max = dp[i]
                pos = i

        ans = [0] * max
        for i in range(max - 1, -1, -1):
            ans[i] = arr[pos]
            pos = p[pos]

        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.longestIncreasingSubsequence(N, arr)
        for val in res:
            print(val, end=" ")
        print()
# } Driver Code Ends
