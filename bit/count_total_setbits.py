# User function Template for python3


class Solution:
    def countBits(self, N):
        # code here
        ans = 0
        for i in range(31, 0, -1):
            if N & (1 << i):
                ans += N % (1 << i) + 1 + (1 << i - 1) * i
                N &= (1 << i) - 1
        if N % 2:
            ans += 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        print(ob.countBits(N))
# } Driver Code Ends
