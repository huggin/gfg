# User function Template for python3


class Solution:
    def count(self, N):
        # code here
        ans = []
        n = 1
        m = 0
        while n <= N:
            ans.append(n)
            n = (n << 1) + m
            m = 1 - m
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    ob = Solution()
    t = int(input())
    for _ in range(t):
        N = int(input())
        ans = ob.count(N)
        print(*ans)


# } Driver Code Ends
