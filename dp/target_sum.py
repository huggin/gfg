# User function Template for python3

class Solution:
    def findTargetSumWays(self, arr, N, target):
        # code here
        s = sum(arr)
        if s + target < 0 or (s + target) % 2:
            return 0

        t = (s + target) // 2
        dp = [0 for _ in range(t+1)]
        dp[0] = 1
        for a in arr:
            for i in range(t, -1, -1):
                if i - a >= 0:
                    dp[i] += dp[i-a]

        return dp[t]


# {
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))
        target = int(input())
        ob = Solution()
        print(ob.findTargetSumWays(arr, N, target))
# } Driver Code Ends
