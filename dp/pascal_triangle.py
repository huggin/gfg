# User function Template for python3


# User function Template for python3
class Solution:
    def nthRowOfPascalTriangle(self, n):
        # code here
        if n == 1:
            return [1]

        mod = int(1e9 + 7)

        dp = [[1 for _ in range(n)] for _ in range(2)]
        for i in range(1, n):
            for j in range(1, i):
                dp[i % 2][j] = (dp[1 - i % 2][j - 1] + dp[1 - i % 2][j]) % mod

        return dp[1 - n % 2]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        ob = Solution()
        ans = ob.nthRowOfPascalTriangle(n)
        for x in ans:
            print(x, end=" ")
        print()
        tc = tc - 1
# } Driver Code Ends
