# User function Template for python3
class Solution:
    def perfectSum(self, arr, n, sum):
        # code here
        M = int(1e9 + 7)
        dp = [0 for _ in range(sum + 1)]
        dp[0] = 1
        for a in arr:
            for i in range(sum, -1, -1):
                if i - a >= 0:
                    dp[i] = (dp[i - a] + dp[i]) % M

        return dp[sum]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, sum = input().split()
        n, sum = int(n), int(sum)
        arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.perfectSum(arr, n, sum)
        print(ans)

# } Driver Code Ends
