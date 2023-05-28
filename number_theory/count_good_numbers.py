# User function Template for python3


class Solution:
    def binpow(self, a, b, m):
        ans = 1
        while b:
            if b & 1:
                ans = ans * a % m
            a = a * a % m
            b >>= 1
        return ans

    def countGoodNumbers(self, N):
        # Code here
        M = int(1e9 + 7)
        ans = self.binpow(4, N // 2, M) * self.binpow(5, N - N // 2, M) % M

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        res = ob.countGoodNumbers(N)
        print(res)
# } Driver Code Ends
