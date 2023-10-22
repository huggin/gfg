# User function Template for python3
class Solution:
    def maxSumIS(self, Arr, n):
        # code here
        dp = [0] * n
        dp[0] = Arr[0]
        for i in range(1, n):
            dp[i] = Arr[i]
            for j in range(i):
                if Arr[i] > Arr[j]:
                    dp[i] = max(dp[i], dp[j] + Arr[i])

        return max(dp)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        Arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.maxSumIS(Arr, n)
        print(ans)

# } Driver Code Ends
