# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def sieve(self):
        ma = 200001
        self.prime = [1] * ma
        self.prime[0] = self.prime[1] = 0
        i = 2
        while i * i < ma:
            if self.prime[i]:
                for j in range(i * i, ma, i):
                    self.prime[j] = 0
            i += 1

    def findPrimeFactors(self, N):
        # Code here
        ans = []
        i = 2
        while i <= N:
            while N % i == 0:
                N //= i
                ans.append(i)
            i += 1
        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    ob = Solution()
    ob.sieve()
    for _ in range(t):
        n = int(input())
        ans = ob.findPrimeFactors(n)
        for v in ans:
            print(v, end=" ")
        print()
# } Driver Code Ends
