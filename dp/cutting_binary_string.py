# User function Template for python3


class Solution:
    def solve(self, s, k, n):
        if k == n:
            return 0
        if k > n:
            return 100

        if self.dp[k] != -1:
            return self.dp[k]

        ans = 100
        for e in self.a:
            if s[k : k + len(e)] == e:
                ans = min(ans, 1 + self.solve(s, k + len(e), n))

        self.dp[k] = ans
        return ans

    def cuts(self, s):
        # code here
        self.a = list(bin(5**i)[2:] for i in range(22))
        n = len(s)
        self.dp = [-1] * n
        ans = self.solve(s, 0, n)
        if ans >= 100:
            return -1
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        print(solObj.cuts(s))

# } Driver Code Ends
