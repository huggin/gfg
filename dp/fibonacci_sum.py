# User function Template for python3


class Solution:
    def fibSum(self, N):
        # code here
        MOD = int(1e9 + 7)
        a, b = 0, 1
        ans = 1
        for _ in range(2, N + 1):
            a, b = b, (a + b)
            if b > MOD:
                b -= MOD
            ans += b
            if ans > MOD:
                ans -= MOD
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        print(ob.fibSum(N))
# } Driver Code Ends
