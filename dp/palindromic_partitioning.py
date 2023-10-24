# User function Template for python3


class Solution:
    def palindromicPartition(self, s):
        # code here
        n = len(s)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1

        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = 1

        for k in range(2, n):
            for i in range(n - k):
                j = i + k
                if s[i] == s[j] and dp[i + 1][j - 1] == 1:
                    dp[i][j] = 1

        dp2 = [n] * (n + 1)
        dp2[0] = 0

        for i in range(1, n + 1):
            for j in range(0, i):
                if dp[j][i - 1] == 1:
                    dp2[i] = min(dp2[i], 1 + dp2[j])

        return dp2[n] - 1


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        string = input()

        ob = Solution()
        print(ob.palindromicPartition(string))
# } Driver Code Ends
