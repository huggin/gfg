# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def countPartitions(self, n, d, arr):
        # Code here
        m = 1000000007
        s = sum(arr)
        if s - d < 0 or (s - d) % 2 == 1:
            return 0

        target = (s - d) // 2

        dp = [0 for _ in range(target + 1)]
        dp[0] = 1
        for a in arr:
            for i in range(target, -1, -1):
                if i >= a:
                    dp[i] = (dp[i - a] + dp[i]) % m

        return dp[target]


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, d = list(map(int, input().split()))
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.countPartitions(n, d, arr)
        print(res)
# } Driver Code Ends
