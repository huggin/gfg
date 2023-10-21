# User function Template for python3


class Solution:
    def power(self, a, b, m):
        ans = 1
        while b > 0:
            if b & 1:
                ans = ans * a % m
            a = a * a % m
            b >>= 1
        return ans

    def numberOfPaths(self, M, N):
        a = 1
        b = 1
        MOD = int(1e9 + 7)
        for i in range(1, M):
            a = a * (N + i - 1) % MOD
            b = b * i % MOD

        return a * self.power(b, MOD - 2, MOD) % MOD


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    ob = Solution()
    t = int(input())
    for _ in range(t):
        M, N = map(int, input().split())
        ans = ob.numberOfPaths(M, N)
        print(ans)


# } Driver Code Ends
