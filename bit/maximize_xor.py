# User function Template for python3


class Solution:
    def maximize_xor_count(self, n):
        # Code here
        ans = 0
        k = 1
        while n:
            if (n & 1) == 0:
                ans += k
            n >>= 1
            k <<= 1
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.maximize_xor_count(n)
        print(ans)


# } Driver Code Ends
