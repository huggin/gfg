# User function Template for python3
class Solution:
    def multiple(self, a, b):
        c = [[0, 0], [0, 0]]
        c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % self.M
        c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % self.M
        c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % self.M
        c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % self.M
        return c

    def binpow(self, a, N):
        ans = [[1, 0], [0, 1]]
        while N > 0:
            if N & 1:
                ans = self.multiple(ans, a)
            a = self.multiple(a, a)
            N >>= 1
        return ans

    def countStrings(self, N):
        # Code here
        self.M = int(1e9 + 7)
        a = [[1, 1], [1, 0]]
        a = self.binpow(a, N)
        return (a[0][0] + a[0][1]) % self.M


# {
# Driver Code Starts
# Initial Template for Python 3
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    while T > 0:
        ob = Solution()
        print(ob.countStrings(int(input())))

        T -= 1
# } Driver Code Ends
