# User function Template for python3


class Solution:
    def NumberofLIS(self, n, arr):
        # Code here
        dp = [1] * n
        cnt = [1] * n
        ma = 0
        for i in range(1, n):
            for j in range(i):
                if arr[j] < arr[i]:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        cnt[i] = cnt[j]
                    elif dp[i] == dp[j] + 1:
                        cnt[i] += cnt[j]
            ma = max(ma, dp[i])

        return sum(cnt[i] for i in range(n) if dp[i] == ma)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.NumberofLIS(n, arr))
# } Driver Code Ends
