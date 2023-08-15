class Solution:
    def findCatalan(self, n: int) -> int:
        # code here
        M = int(1e9 + 7)

        def div(a):
            b = M - 2
            ans = 1
            while b > 0:
                if b & 1:
                    ans = (ans * a) % M
                b >>= 1
                a = (a * a) % M
            return ans

        fact = [0] * (2 * n + 1)
        fact[0] = 1
        for i in range(1, 2 * n + 1):
            fact[i] = (fact[i - 1] * i) % M

        ans = fact[2 * n] * div(fact[n] * fact[n + 1] % M) % M
        return ans


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        obj = Solution()
        res = obj.findCatalan(n)

        print(res)


# } Driver Code Ends
