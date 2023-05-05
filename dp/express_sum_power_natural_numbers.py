# User function Template for python3
class Solution:
    def numOfWays(self, n, x):
        # code here
        M = int(1e9) + 7
        p = []
        i = 1
        while True:
            if pow(i, x) <= n:
                p.append(pow(i, x))
                i += 1
            else:
                break

        dp = [0] * (n + 1)
        dp[0] = 1
        for a in p:
            for i in range(n, -1, -1):
                if i - a >= 0:
                    dp[i] = (dp[i - a] + dp[i]) % M

        return dp[n]


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, x = input().split()
        n = int(n)
        x = int(x)
        ob = Solution()
        print(ob.numOfWays(n, x))

# } Driver Code Ends
