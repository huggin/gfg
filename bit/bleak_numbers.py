# User function Template for python3


class Solution:
    def is_bleak(self, n):
        # Code here
        def setbit(k):
            ans = 0
            while k > 0:
                ans += 1
                k &= k - 1
            return ans

        for i in range(1, 32):
            if setbit(n - i) == i:
                return 0
        return 1


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.is_bleak(n)
        print(ans)

# } Driver Code Ends
